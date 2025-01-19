n, m = map(int, input().split())
G = {}

for i in range(m):
    u, v = map(int, input().split())
    G[u] = G.get(u, []) + [v]

comp = {}
vis = [False for i in range(n + 1)]
compId = [0 for i in range(n + 1)]


def dfs(u, root):
    global vis, comp, compId, G

    vis[u] = True
    compId[u] = root
    comp[root] = comp.get(root, []) + [u]

    for v in G[u]:
        if not vis[v]:
            dfs(v, root)


for i in range(1, n + 1):
    if vis[i]:
        continue

    dfs(i, i)

print(compId)
print(comp)
