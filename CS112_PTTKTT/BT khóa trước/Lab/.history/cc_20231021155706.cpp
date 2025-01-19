#include <bits/stdc++.h>
using namespace std;

vector<int> G[100005];
bool vis[100005];
int compId[100005];
vector<int> comp[100005];

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
    for (int node : res) {
        cout << node << " ";
    }

    return 0;
}
