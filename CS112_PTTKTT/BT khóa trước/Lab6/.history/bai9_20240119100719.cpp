#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int h[n], par[n];
    bool used[n] = { false };
    vector<vector<int>> g(n);

    for (int i = 0, a, b; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    // ta co n dinh, va n - 1, lien thong => tree
    h[0] = 1;
    par[0] = 0;

    // dfs
    stack<int> st;
    st.push(0);

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (used[u])
            continue;

        used[u] = true;

        for (auto& v : g[u]) {
            if (!used[v]) {
                h[v] = h[u] + 1;
                par[v] = u;
                st.push(v);
            }
        }
    }

    for (int i = 0, a, b; i < q; ++i) {
        cin >> a >> b;
        --a, --b;

        // tim node cha chung
        int u = a, v = b;
        // cout << "u = " << u << " v = " << v << " " << a << " " << b << "\n";

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
