#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e, n;
    cin >> v >> e >> n;
    
    int** a = new int*[v + 1];
    for (int i = 1; i <= v; ++i) {
        a[i] = new int[v + 1];

        for (int j = 1; j <= v; ++j)
            a[i][j] = 0;
    }

    for (int i = 0; i < e; ++i) {
        int u, v; cin >> u >> v;
        a[u][v] = 1;
    }

    for (int i = 0; i < n; ++i) {
        int q; cin >> q;
        if (q == 1) {
            int u, v; cin >> u >> v;
            cout << (a[u][v] ? "TRUE" : "FALSE");
        } else if (q == 2) {
            int t; cin >> t;
            for (int j = 1; j <= v; ++j) {
                if (i != t && a[t][j]) {
                    cout << j << " ";
                }
            }
        }

        cout << "\n";
    }
}
