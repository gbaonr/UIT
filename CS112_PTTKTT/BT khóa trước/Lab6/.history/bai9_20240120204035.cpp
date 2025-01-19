#include <iostream>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int h[n], par[n], parJump[n];
    bool used[n] = { false };
    vector<vector<int>> g(n);

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
                cout << u << endl;
            } else {
                v = parJump[v];
                cout << v << endl;
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