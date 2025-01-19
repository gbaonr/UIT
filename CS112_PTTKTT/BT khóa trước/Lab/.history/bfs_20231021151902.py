v, n = map(int, input().split())
c2i = {}
i2c = {}
G = {}

for i, t in enumerate(input().split()):
    c2i[t] = i
    i2c[i] = t

print(c2i)

for i in range(v):
    G[i] = []
    w = map(int, input().split())

    for j, t in enumerate(w):
        if t != 0:
            G[i].append(i2c[j])

for i in range(n):
    u, v = input().split()

print(G)