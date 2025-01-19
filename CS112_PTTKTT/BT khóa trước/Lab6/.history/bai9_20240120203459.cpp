#include <iostream>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;

// vector<int> h, par, parJump;
// vector<vector<int>> g;
// vector<bool> used;
// int block_size = 0;
// int n, q;

// void dfs(int x)
// {
//     used[x] = true;

//     for (auto& v : g[x]) {
//         if (!used[v]) {
//             h[v] = h[x] + 1;
//             par[v] = x;

//             if (h[v] % block_size == 0)
//                 parJump[v] = par[v];
//             else
//                 parJump[v] = parJump[x];

//             dfs(v);
//         }
//     }
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int h[n], par[n], parJump[n];
    bool used[n] = { false };
    vector<vector<int>> g(n);

    // h.assign(n, 0);
    // g.assign(n, vector<int>());
    // used.assign(n, false);
    // par.assign(n, 0);
    // parJump.assign(n, 0);

    int block_size = log2(n);

    for (int i = 0, a, b; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    // ta co n dinh, va n - 1, lien thong => tree
    h[0] = 1;
    par[0] = 0;

    stack<int> st;
    st.push(0);

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        used[u] = true;

        for (auto& v : g[u]) {
            if (!used[v]) {
                h[v] = h[u] + 1;
                par[v] = u;

                if ((h[v] + 1) % block_size == 0)
                    parJump[v] = par[v];
                else
                    parJump[v] = parJump[u];

                st.push(v);
            }
        }
    }

    for (int i = 0, a, b; i < q; ++i) {
        cin >> a >> b;
        --a, --b;

        // tim node cha chung
        int u = a;
        int v = b;

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

        cout << h[a] + h[b] - 2 * h[u] << "\n";
    }
}