#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> G(n, vector<int>());

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int u; cin >> u;
            if (u) G[i].push_back(j);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (G[i].size() == 0) {
            continue;
        }

        cout << i + 1 << "->";
        for (auto &v : G[i]) {
            cout << v + 1 << " ";
        }
        cout << "\n";
    }
}