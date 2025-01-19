#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    map<string, map<string, bool>> adj;

    while (1) {
        cin >> q;

        if (q == 0) break;
        if (q == 1) {
            string u; cin >> u;
            adj[u] = map<string, bool>();  
            continue;
        }
        if (q == 2) {
            string u, v; cin >> u >> v;
            adj[u][v] = 1;
            continue;
        }
        if (q == 3) {
            string u, v; cin >> u >> v;
            cout << (adj.find(u) == adj.end() || adj[u].find(v) == adj[u].end() ? "FALSE" : "TRUE") << endl;
            continue;
        }
        if (q == 4) {
            string u; cin >> u;
            if (adj.find(u) == adj.end()) {
                cout << 0 << endl;
                continue;
            }
            cout << adj[u].size() << endl;
        }
    }
}