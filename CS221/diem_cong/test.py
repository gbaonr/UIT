# from main_22520069 import run1
from main_22520109 import run
import pandas as pd
import kagglehub
import os


def load_sms_data():
    # Tải dataset
    path = kagglehub.dataset_download("uciml/sms-spam-collection-dataset")

    # Tìm file spam.csv trong thư mục con
    for root, dirs, files in os.walk(path):
        for file in files:
            if file.lower() == "spam.csv":
                file_path = os.path.join(root, file)
                break
        else:
            continue
        break
    else:
        raise FileNotFoundError("Không tìm thấy file spam.csv trong dataset.")

    # Đọc dữ liệu
    dataset = pd.read_csv(file_path, encoding="windows-1252")
    dataset = dataset.drop(columns=["Unnamed: 2", "Unnamed: 3", "Unnamed: 4"])
    dataset.rename(columns={"v1": "Class", "v2": "Message"}, inplace=True)

    texts = dataset["Message"].tolist()
    labels = dataset["Class"].map(lambda x: 1 if x == "spam" else 0).tolist()

    return texts, labels


if __name__ == "__main__":
    traintext, trainlabel = load_sms_data()
    run(traintext, trainlabel)
    print("✔ Đã ghi 1000 câu vào 'spam.txt' và 'ham.txt'")
