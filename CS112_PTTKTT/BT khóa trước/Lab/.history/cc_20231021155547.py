n, m = map(int, input().split())
G = {}

for i in range(m):
    u, v = map(int, input().split())
    G[u] = G.get(u, []) + [v]
    G[v] = G.get(v, []) + [u]

comp = {}
vis = [False for _ in range(n + 1)]
compId = [0 for _ in range(n + 1)]


def dfs(u, root):
    vis[u] = True
    compId[u] = root
    comp[root] = comp.get(root, []) + [u]

    for v in G[u]:
        if not vis[v]:
            dfs(v, root)


for i in range(1, n + 1):
    if vis[i] or i not in G:
        continue

    dfs(i, i)


attack = int(input())
res = sorted(comp[compId[attack]])

print(len(res))
print(" ".join(map(str, res)))
