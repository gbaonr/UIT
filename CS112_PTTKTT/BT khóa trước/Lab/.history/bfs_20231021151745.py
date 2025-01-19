v, n = map(int, input().split())
c2i = {}
G = {}

for i, t in enumerate(input().split()):
    c2i[t] = i

print(c2i)

for i in range(v):
    G[i] = []
    w = map(int, input().split())

    for j, t in enumerate(w):
        if j != 0:
            G[i].append(c2i[t])

for i in range(n):
    u, v = input().split()