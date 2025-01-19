v, n = map(int, input().split())
c2i = {}
i2c = {}
G = {}

for i, t in enumerate(input().split()):
    c2i[t] = i
    i2c[i] = t

for i in range(v):
    G[i2c[i]] = []
    w = map(int, input().split())

    for j, t in enumerate(w):
        if t != 0:
            G[i2c[i]].append((i2c[j], t))

for i in range(n):
    a, b = input().split()

    # bfs with save path and total weight
    vis = {}
    path = {}
    weight = {}
    count_open = {}

    for i in range(v):
        vis[i2c[i]] = False
        path[i2c[i]] = []
        weight[i2c[i]] = 0
        count_open[i2c[i]] = 0
        
    q = []
    q.append(a)
    vis[a] = True
    count = 0

    while len(q) > 0:
        t = q.pop(0)
        count += 1
        count_open[t] = count

        for c, w in G[t]:
            if not vis[c]:
                vis[c] = True
                path[c] = path[t] + [t]
                weight[c] = weight[t] + w
                # count_open[c] = count
                q.append(c)

    if not len(path[b]):
        print('-unreachable-')
        print(f"{count_open[b] if count_open[b] != 0 else 1} 0")
        continue

    print(" ".join(path[b]) + " " + b)
    print(count_open[b], weight[b])