#include <bits/stdc++.h>
using namespace std;

vector<int> h, par;
vector<vector<int>> g;
vector<bool> used;
int n, q;

void dfs(int x)
{
    used[x] = true;

    for (auto& v : g[x]) {
        if (!used[v]) {
            h[v] = h[x] + 1;
            par[v] = x;
            dfs(v);
        }
    }
}

int main()
{
    cin >> n >> q;

    h.assign(n, 0);
    g.assign(n, vector<int>());
    used.assign(n, false);

    for (int i = 0, a, b; i < n; ++i) {
        cin >> a >> b;
        --a, --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    // ta co n dinh, va n - 1, lien thong => tree
    h[0] = 1;
    par[0] = 0;
    dfs(0);

    for (int i = 0, a, b; i < q; ++i) {
        cin >> a >> b;
        --a, --b;

        cout << a << " " << h[a] << "\n";
        cout << b << " " << h[b] << "\n";
        cout << "\n";
    }
}
