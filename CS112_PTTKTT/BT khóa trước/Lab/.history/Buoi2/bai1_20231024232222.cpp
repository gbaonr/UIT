#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e, n;
    cin >> v >> e >> n;

    vector<vector<bool>> G(v, vector<bool>(v, 0));
    vector<vector<int>> H(v, vector<int>());
    for (int i = 0; i < e; ++i) {
        int u, v; cin >> u >> v;
        G[--u][--v] = 1;
        H[u].push_back(v);
    }

    for (int i = 0; i < v; ++i) {
        sort(H[i].begin(), H[i].end());
    }

    for (int i = 0; i < n; ++i) {
        int q; cin >> q;
        if (q == 1) {
            int u, v; cin >> u >> v;
            --u; --v;
            cout << (G[u][v] ? "TRUE" : "FALSE") << endl;
        } else {
            int u; cin >> u;
            if (H[u].size() == 0) {
                cout << "NONE" << endl;
                continue;
            } else {
                for (int j = 0; j < H[u].size(); ++j) {
                    cout << H[u][j] + 1 << " ";
                }
                cout << endl;
            }
        }
    }
}