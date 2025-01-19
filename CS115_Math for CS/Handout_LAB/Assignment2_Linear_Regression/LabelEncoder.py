from sklearn.preprocessing import LabelEncoder

# Sample data
labels = ['cat', 'dog', 'bird', 'cat', 'dog', 'bird']

# Create a LabelEncoder instance and fit it to the data
label_encoder = LabelEncoder()
label_encoder.fit(labels)
print("label encoder: ", label_encoder)

# Transform the labels into their integer representations
encoded_labels = label_encoder.transform(labels)

print("Original Labels:", labels)
print("Encoded Labels:", encoded_labels)
