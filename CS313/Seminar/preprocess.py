import math
import pandas as pd
import numpy as np
from collections import Counter
import joblib
from sklearn.decomposition import PCA


# func to compute entropy
def calculate_entropy(text):
    if len(text) == 0:
        return 0
    counts = Counter(text)
    probs = [count / len(text) for count in counts.values()]
    return -sum(p * np.log2(p) for p in probs if p > 0)


def manual_features_extractor(host):
    features = {}
    features["length"] = len(host)
    features["digit_ratio"] = (
        sum(c.isdigit() for c in host) / len(host) if len(host) > 0 else 0
    )
    features["vowel_ratio"] = (
        sum(c.lower() in "aeiou" for c in host) / len(host) if len(host) > 0 else 0
    )
    features["entropy"] = calculate_entropy(host)
    features["unique_chars"] = len(set(host))

    return features


# Tính entropy
def shannon_entropy(string):
    if len(string) == 0:
        return 0
    freq = Counter(string)
    probs = [freq[c] / len(string) for c in freq]
    return -sum(p * math.log2(p) for p in probs if p > 0)


# Tính số lượng n-grams phổ biến
def count_common_ngrams(domain, common_ngrams):
    return sum(1 for i in range(len(domain) - 2) if domain[i : i + 3] in common_ngrams)


# Danh sách n-grams phổ biến
common_ngrams = {"com", "net", "org", "goo", "www", "abc", "xyz"}


# Hàm trích xuất đặc trưng từ một mẫu duy nhất
def extra_features_extractor(host):
    domain = host.split(".")[0]  # Tách domain từ host

    # Đặc trưng độ dài
    length_domain = len(domain)
    length_host = len(host)
    ratio_domain_host = length_domain / length_host if length_host > 0 else 0

    # Đặc trưng số ký tự
    num_digits = sum(c.isdigit() for c in domain)
    num_letters = sum(c.isalpha() for c in domain)
    digit_ratio = num_digits / length_domain if length_domain > 0 else 0
    vowels = "aeiou"
    num_vowels = sum(c in vowels for c in domain)
    vowel_ratio = num_vowels / length_domain if length_domain > 0 else 0
    consonant_ratio = (
        (num_letters - num_vowels) / length_domain if length_domain > 0 else 0
    )

    # Entropy
    entropy_domain = shannon_entropy(domain)
    entropy_host = shannon_entropy(host)

    # N-gram phổ biến
    common_ngram_count = count_common_ngrams(domain, common_ngrams)

    # Đếm phụ âm liên tiếp
    consonant_sequences = "".join(c if c not in vowels else " " for c in domain).split()
    max_consecutive_consonants = (
        max(map(len, consonant_sequences)) if consonant_sequences else 0
    )

    # Đếm dấu chấm trong host
    num_dots = host.count(".")

    # Trả về dictionary chứa đặc trưng
    return {
        "length_domain": length_domain,
        "length_host": length_host,
        "ratio_domain_host": ratio_domain_host,
        "num_digits": num_digits,
        "num_letters": num_letters,
        "digit_ratio": digit_ratio,
        "vowel_ratio": vowel_ratio,
        "consonant_ratio": consonant_ratio,
        "entropy_domain": entropy_domain,
        "entropy_host": entropy_host,
        "common_ngram_count": common_ngram_count,
        "max_consecutive_consonants": max_consecutive_consonants,
        "num_dots": num_dots,
    }


def preprocess_sample(host):
    # Load vectorizer đã train
    vectorizer = joblib.load("vectorizer.pkl")

    # Trích xuất đặc trưng thủ công
    manual_feats = manual_features_extractor(host)
    extra_feats = extra_features_extractor(host)

    # Chuyển từ dictionary sang numpy array
    manual_feats_array = np.array(
        list(manual_feats.values()), dtype=np.float16
    ).reshape(1, -1)
    extra_feats_array = np.array(list(extra_feats.values()), dtype=np.float16).reshape(
        1, -1
    )

    # Vector hóa host bằng TF-IDF
    host_tfidf_features = vectorizer.transform([host]).toarray().astype(np.float16)

    # PCA
    pca = joblib.load("pca.pkl")
    X = pca.transform(host_tfidf_features)
    print(f"Final X shape: {X.shape}")

    # Kết hợp tất cả các đặc trưng thành 1 feature vector
    Xisdga = X
    Xsc = np.hstack([manual_feats_array, extra_feats_array, X])

    # Kiểm tra shape của từng phần
    print(f"Xisdga shape: {Xisdga.shape}")
    print(f"Xsc shape: {Xsc.shape}")

    return Xisdga, Xsc
