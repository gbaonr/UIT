#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e; // so dinh, so canh
    cin >> v >> e;

    vector<string> a(v); // chua ten cac dinh
    unordered_map<string, vector<string>> g; // chua danh sach ke cua cac dinh
    unordered_map<string, int> colors; // chua mau cua cac dinh

    for (int i = 0; i < v; ++i) {
        cin >> a[i];
        colors[a[i]] = -1;
    }

    for (int i = 0; i < e; ++i) {
        string u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (auto u : a) {
        unordered_set<int> usedColors;

        for (auto v : g[u])
            if (colors[v] != -1)
                usedColors.insert(colors[v]);

        for (int i = 0;; ++i)
            if (!usedColors.count(i)) {
                colors[u] = i;
                break;
            }
    }

    for (auto u : a)
        cout << colors[u] << " ";
}