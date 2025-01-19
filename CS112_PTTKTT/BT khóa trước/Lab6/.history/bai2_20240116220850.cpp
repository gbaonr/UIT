#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<string> a(v);
    unordered_map<string, vector<string>> g;
    unordered_map<string, int> colors;

    for (int i = 0; i < v; ++i)
        cin >> a[i];

    for (int i = 0; i < e; ++i) {
        string u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
        colors[u] = -1;
    }

    for (auto u : a) {
        unordered_set<int> usedColors;

        for (auto v : g[u])
            if (colors[v] != -1)
                usedColors.insert(colors[v]);

        for (auto &x : usedColors)
            cout << x << " ";

        for (int i = 0;; ++i)
            if (!usedColors.count(i)) {
                colors[u] = i;
                break;
            }
    }

    for (auto u : a)
        cout << colors[u] << endl;
}