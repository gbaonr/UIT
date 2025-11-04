from btth3_22520109 import run

traintext = [["this", "is", "a", "book"], ["I", "love", "it"]]
trainlabel = [["DT", "VBZ", "DT", "NN"], ["PRP", "VBP", "PRP"]]
testtext = [["this", "is", "a", "book"], ["I", "love", "it"]]
results = run(traintext, trainlabel, testtext)
print("Results:")
for i, res in enumerate(results):
    print(f"Sentence {i + 1}: {res}")
# Output the results
# Results:
