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
        }
    }
}