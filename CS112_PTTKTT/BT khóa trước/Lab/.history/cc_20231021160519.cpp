#include <bits/stdc++.h>
using namespace std;

bool vis[1000005];
int compId[1000005];
map<int, vector<int>> G;
map<int, vector<int>> comp;

void dfs(int u, int root)
{
    vis[u] = true;
    compId[u] = root;
    comp[root].push_back(u);

    for (int v : G[u]) {
        if (!vis[v]) {
            dfs(v, root);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) 
        comp[i] = vector<int>();

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && !G[i].empty()) {
            dfs(i, i);
        }
    }

    int attack;
    cin >> attack;

    vector<int> res = comp[compId[attack]];
    sort(res.begin(), res.end());

    cout << res.size() << "\n";
    for (int v : res) {
        cout << v << " ";
    }

    return 0;
}
