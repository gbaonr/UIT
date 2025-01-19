#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e; cin >> v >> e;

    map<string, int> deg;
    vector<string> orders;

    for (int i = 0; i < v; ++i) {
        string c; cin >> c;
        orders.push_back(c);
        deg[c] = 0;
    }

    for (int i = 0; i < v; ++i) {
        string u, v; cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    for (auto &v : orders) {
        cout << deg[v] << endl;
    }
}