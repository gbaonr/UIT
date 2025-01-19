#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    unordered_map<string, vector<string>> g;
    unordered_map<string, int> colors;

    for (int i = 0; i < v; ++i) {
        string u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
        colors[u] = -1;
    }

    for (auto u : g) {
        unordered_set<int> usedColors;
        for (auto v : u.second)
            if (colors[v] != -1)
                usedColors.insert(colors[v]);

        for (int i = 0;; ++i)
            if (!usedColors.count(i)) {
                colors[u.first] = i;
                break;
            }
    }
}