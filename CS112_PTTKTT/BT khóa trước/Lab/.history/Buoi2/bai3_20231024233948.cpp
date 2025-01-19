#include <bits/stdc++.h>
using namespace std;

int main() {
    int e; cin >> e;
    map<string, map<string, bool>> G;
    set<string> vertices;

    for (int i = 0; i < e; ++i) {
        string u, v; cin >> u >> v;
        G[u][v] = 1;
        vertices.insert(u);
    }

    for (auto &v : vertices) {
        for (auto &u : vertices) {
            if (u == v) continue;
            if (G[u][v] * G[v][u] == 0) {
                cout << "FALSE" << endl;
                return 0;
            }
        }
    }

    cout << "TRUE";
}