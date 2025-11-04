import nltk
from nltk.tag import UnigramTagger
from nltk.tag import DefaultTagger

def run(traintext, trainlabel, testtext):
    """
    Hàm huấn luyện và dự đoán nhãn từ loại cho tập test.
    
    Tham số:
    - traintext: List[List[str]] - các câu huấn luyện, mỗi câu là danh sách từ.
    - trainlabel: List[List[str]] - các nhãn tương ứng với từng câu.
    - testtext: List[List[str]] - các câu cần dự đoán nhãn.

    Trả về:
    - List[List[str]] - các nhãn dự đoán tương ứng với mỗi câu trong testtext.
    """

    # Ghép từ và nhãn thành các cặp (word, tag)
    train_data = []
    for words, tags in zip(traintext, trainlabel):
        train_data.append(list(zip(words, tags)))

    # Gán nhãn mặc định là "NN" cho các từ không thấy trong tập huấn luyện
    default_tagger = DefaultTagger('NN')

    # Dùng UnigramTagger với backoff là default_tagger
    unigram_tagger = UnigramTagger(train_data, backoff=default_tagger)

    # Dự đoán nhãn cho tập test
    predicted_labels = []
    for sentence in testtext:
        tagged_sentence = unigram_tagger.tag(sentence)
        tags = [tag for (_, tag) in tagged_sentence]
        predicted_labels.append(tags)

    return predicted_labels

if __name__ == "__main__":
    traintext = [["this", "is", "a", "book"], ["I", "love", "it"]]
    trainlabel = [["DT", "VBZ", "DT", "NN"], ["PRP", "VBP", "PRP"]]
    testtext = [["this", "is", "it"], ["I", "read", "a", "book"]]

    predictions = run(traintext, trainlabel, testtext)
    print(predictions)
