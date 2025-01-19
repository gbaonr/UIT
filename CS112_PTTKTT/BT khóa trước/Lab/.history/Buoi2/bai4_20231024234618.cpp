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
}