import os
import random
import numpy as np
from collections import defaultdict, Counter
from nltk import word_tokenize
from sklearn.linear_model import LogisticRegression
from sklearn.feature_extraction.text import CountVectorizer
import nltk

random.seed(42)
nltk.download("punkt")
nltk.download("stopwords")
from nltk.corpus import stopwords

STOPWORDS = set(stopwords.words("english"))


class BigramLanguageModel:
    def __init__(self):
        self.bigram_probs = {}
        self.unigram_counts = defaultdict(int)
        self.vocab = set()

    def train(self, sentences):
        bigram_counts = defaultdict(Counter)
        for sent in sentences:
            # tokens = ["<s>"] + word_tokenize(sent.lower()) + ["</s>"]
            tokens = (
                ["<s>"]
                + [
                    w
                    for w in word_tokenize(sent.lower())
                    if w.isalpha() and w not in STOPWORDS
                ]
                + ["</s>"]
            )
            for i in range(len(tokens) - 1):
                self.unigram_counts[tokens[i]] += 1
                bigram_counts[tokens[i]][tokens[i + 1]] += 1
                self.vocab.update([tokens[i], tokens[i + 1]])
        self.vocab = list(self.vocab)
        for w1 in bigram_counts:
            total = float(sum(bigram_counts[w1].values()))
            self.bigram_probs[w1] = {}
            for w2 in bigram_counts[w1]:
                self.bigram_probs[w1][w2] = (
                    bigram_counts[w1][w2] + 1 / total + 1e-6
                )  # Thêm một hằng số nhỏ để tránh chia cho 0

    def generate_sentence(self, max_len=20):
        sentence = []
        w = "<s>"
        for _ in range(max_len):
            next_words = self.bigram_probs.get(w, {})
            if not next_words:
                break
            words = list(next_words.keys())
            probs = list(next_words.values())
            w = random.choices(words, probs)[0]
            if w == "</s>":
                break
            sentence.append(w)
        return " ".join(sentence)


def filter_generated_sentences(
    model, label, clf, vectorizer, n_samples=1000, max_attempts=10000
):
    generated = set()
    accepted = []
    attempts = 0
    while len(accepted) < n_samples and attempts < max_attempts:
        sentence = model.generate_sentence()
        if sentence in generated:
            attempts += 1
            continue
        generated.add(sentence)
        vec = vectorizer.transform([sentence])
        pred = clf.predict(vec)[0]
        if pred == label:
            accepted.append(sentence)
        attempts += 1
    return accepted


def run(traintext, trainlabel):
    if len(STOPWORDS) != 0:
        print("STOPWORDS is available, using it to filter words.")

    ham_texts = [traintext[i] for i in range(len(traintext)) if trainlabel[i] == 0]
    spam_texts = [traintext[i] for i in range(len(traintext)) if trainlabel[i] == 1]

    ham_model = BigramLanguageModel()
    spam_model = BigramLanguageModel()
    ham_model.train(ham_texts)
    spam_model.train(spam_texts)

    vectorizer = CountVectorizer()
    X = vectorizer.fit_transform(traintext)
    y = np.array(trainlabel)
    clf = LogisticRegression(max_iter=1000)
    clf.fit(X, y)

    spam_sents = filter_generated_sentences(
        spam_model, label=1, clf=clf, vectorizer=vectorizer
    )
    ham_sents = filter_generated_sentences(
        ham_model, label=0, clf=clf, vectorizer=vectorizer
    )

    with open("spam.txt", "w", encoding="utf-8") as f:
        for sent in spam_sents:
            f.write(sent + "\n")
    with open("ham.txt", "w", encoding="utf-8") as f:
        for sent in ham_sents:
            f.write(sent + "\n")
