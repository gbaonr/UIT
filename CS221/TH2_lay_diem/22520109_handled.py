import os
import re
import string
import numpy as np
from typing import List
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import BernoulliNB
from sklearn.feature_selection import SelectKBest, chi2
from sklearn.pipeline import Pipeline
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from nltk.corpus import stopwords
import nltk


def preprocess(text):
    text = text.lower()
    text = re.sub(r"[%s]" % re.escape(string.punctuation), " ", text)
    text = re.sub(r"\d+", " ", text)
    return text.strip()


def run(test_data):
    nltk.download("stopwords")
    with open("data.txt", encoding="utf-8") as f:
        data = f.readlines()

    texts, labels = [], []

    for line in data:
        if "\t" not in line:
            continue
        text, label = line.rsplit("\t", 1)
        texts.append(preprocess(text))
        labels.append(label.strip())

    # Khởi tạo stopword từ nltk
    nltk_stopwords = list(stopwords.words("english"))

    # Tạo vectorizer dùng stopword của NLTK
    vectorizer = CountVectorizer(binary=True, stop_words=nltk_stopwords, min_df=3)

    # Fit để biết tổng số feature ban đầu
    X_bin = vectorizer.fit_transform(texts)
    total_features = len(vectorizer.get_feature_names_out())

    # Tìm số lượng feature tối ưu dựa trên hiệu quả
    best_eff, best_k, best_acc, best_features, best_model = 0, 0, 0, [], None
    best_sel = None
    print(f"Total features: {total_features}")
    k = 30
    # k = int(0.02 * total_features)
    # for k in range(1, 100, 1):
    #     sel = SelectKBest(chi2, k=k)
    #     clf = Pipeline(
    #         [("vect", vectorizer), ("sel", sel), ("clf", BernoulliNB(alpha=1.0))]
    #     )
    #     clf.fit(texts, labels)
    #     acc = clf.score(texts, labels)
    #     sf = (total_features - k) / total_features
    #     eff = 2 * sf * acc / (sf + acc)
    #     print(f"Accuracy: {acc:.4f} with k={k}, eff={eff:.4f}")
    #     if eff > best_eff:
    #         # Lưu lại model tốt nhất
    #         best_eff, best_k, best_acc = eff, k, acc
    #         best_sel = sel
    #         best_model = clf
    #         best_features = vectorizer.get_feature_names_out()[sel.get_support()]

    sel = SelectKBest(chi2, k=k)
    clf = Pipeline(
        [("vect", vectorizer), ("sel", sel), ("clf", BernoulliNB(alpha=1.0))]
    )
    clf.fit(texts, labels)
    acc = clf.score(texts, labels)
    sf = (total_features - k) / total_features
    eff = 2 * sf * acc / (sf + acc)
    print(f"Accuracy: {acc:.4f} with k={k}, eff={eff:.4f}")
    if eff > best_eff:
        # Lưu lại model tốt nhất
        best_eff, best_k, best_acc = eff, k, acc
        best_sel = sel
        best_model = clf
        best_features = vectorizer.get_feature_names_out()[sel.get_support()]

    # Dự đoán trên toàn bộ dữ liệu
    print(f"Best k: {best_k}, Best accuracy: {best_acc:.4f}, Best eff: {best_eff:.4f}")

    # test on test data
    # test_data = [preprocess(text) for text in test_data]
    # test_data_vectorized = vectorizer.transform(test_data)
    # test_data_vectorized = test_data_vectorized[:, sel.get_support()]
    # test_data_vectorized = test_data_vectorized[:, :best_k]
    # test_data_pred = best_model.predict(test_data_vectorized)

    # test on test data
    test_data = [preprocess(text) for text in test_data]
    test_data_pred = best_model.predict(test_data)

    # Ghi file pred.txt
    with open("pred.txt", "w", encoding="utf-8") as f:
        for pred in test_data_pred:
            f.write(f"{pred}\n")

    # Ghi file feat.txt
    with open("feat.txt", "w", encoding="utf-8") as f:
        for feat in best_features:
            f.write(f"{feat}\n")


# test_data = [
#     "I really loved the movie. It was fantastic!",
#     "Terrible experience. I will never watch it again.",
#     "An average film with a decent story.",
#     "Great cast and wonderful soundtrack.",
#     "Worst plot ever. Completely boring and predictable.",
# ]

test_raw = """
# Natitude ? Okay . I 'm only going to say it once . COMB yer BEARDS . # lol # wiggers\t0
# NowPlaying : BT feat . Tori Amos - Blue Skies ( radio edit ) on # 1069TheArrow - http : //t.co/R5wuXA9jB6\t0
# NowPlaying : Great White - Once Bitten Twice Shy on # 1069TheArrow - http : //t.co/R5wuXA9jB6\t0
# NowPlaying : Ian Hunter - Once Bitten Twice Shy on # 1069TheArrow - http : //t.co/R5wuXA9jB6\t0
# NowPlaying : The Doors - The WASP ( Texas Radio and the Big Beat ) on # 1069TheArrow - http : //t.co/R5wuXA9jB6\t0
# PDPLive is on November 10th . Get your early bird tickets from http : //t.co/7xcL4Kyiuv @ LifeOfShan http : //t.co/ZcnP1ljoOW\t0
# PacerNation 4/4 on the road ! Perfect way to continue after # iubb have finished # NBA # Pacers # indiana # hoosiers\t0
# RadioFreeNorthwest 218 Covington reads responses & amp ; mocks FBI , Andy on Real Politics , Liv on her awakening , Gretchen http : //t.co/t9JyhAncPR\t0
# RedSox , focus on the # Orioles that knocked you out last year , and not your hatred of the # Yankees for um-teen years ! LOL !\t0
# Royals 2-1 ! ! Fantastic . Ready for tomorrow 's sweep of the disposed O 's . # Yankees 4ever except this month .\t0
# Royals Milwaukee let Yost go.Now they wished they had n't cause they suck.How about now.He 's the guy win or lose . Yankees fire Girardi & # 128073 ; Yost\t0
# RuinAComedian @ midnight Charlie Lapdance\t0
# Skating is for trash .\t0
""".strip()

test_data = [line.rsplit("\t", 1)[0] for line in test_raw.split("\n")]


# run(test_data)
