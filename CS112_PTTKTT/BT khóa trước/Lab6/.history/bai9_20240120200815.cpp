#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<int> h, par, parJump;
vector<vector<int>> g;
vector<bool> used;
int block_size = 0;
int n, q;

void dfs(int x)
{
    used[x] = true;

    for (auto& v : g[x]) {
        if (!used[v]) {
            h[v] = h[x] + 1;
            par[v] = x;

            if (h[v] % block_size == 0)
                parJump[v] = par[v];
            else
                parJump[v] = parJump[x];

            dfs(v);
        }
    }
}

int LCA(int u, int v) {
    while (parJump[u] != parJump[v]) {
        if (h[u] > h[v]) {
            u = parJump[u];
        } else {
            v = parJump[v];
        }
    }

    while (u != v) {
        if (h[u] > h[v]) {
            u = par[u];
        } else {
            v = par[v];
        }
    }

    return u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    h.assign(n, 0);
    g.assign(n, vector<int>());
    used.assign(n, false);
    par.assign(n, 0);
    block_size = (int)sqrt(n);

    for (int i = 0, a, b; i < n - 1; ++i) {
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

        // tim node cha chung
        int u = LCA(a, b);
        // cout << "u = " << u << " v = " << v << " " << a << " " << b << "\n";

        cout << h[a] + h[b] - 2 * h[u] << "\n";
    }
}