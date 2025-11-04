from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

from test import load_sms_data

traintext, trainlabel = load_sms_data()

# B1: Vector hóa
vectorizer = TfidfVectorizer()
X_train = vectorizer.fit_transform(traintext)

# B2: Huấn luyện Logistic Regression
clf = LogisticRegression()
clf.fit(X_train, trainlabel)

# Đọc 1000 câu đã sinh từ file
with open("spam.txt", "r", encoding="utf-8") as f:
    spam_sentences = [line.strip() for line in f.readlines()]

with open("ham.txt", "r", encoding="utf-8") as f:
    ham_sentences = [line.strip() for line in f.readlines()]

# Ghép lại dữ liệu tạo sinh
X_gen = spam_sentences + ham_sentences
y_gen = [1] * len(spam_sentences) + [0] * len(ham_sentences)

# Vector hóa
X_gen_vec = vectorizer.transform(X_gen)

# Dự đoán
y_pred = clf.predict(X_gen_vec)

# Tính độ chính xác
acc = accuracy_score(y_gen, y_pred)
print(f"Accuracy trên dữ liệu sinh: {acc:.4f}")

