v, n = map(int, input().split())
c2i = {}
G = {}

for i, t in enumerate(input().split()):
    c2i[t] = i

for i in range(v):
    G[i] = []

    for j, t in enumerate(input().split()):
        if j != 0:
            G[i].append(c2i[t])

print(G[i])