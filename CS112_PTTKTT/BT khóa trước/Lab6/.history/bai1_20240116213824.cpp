#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e, n;
    cin >> v >> e >> n;

    vector<string> a(v);
    unordered_map<string, vector<string>> g;
    unordered_map<string, int> colors;
    unordered_set<int> usedColors;

    for (int i = 0; i < v; ++i)
        cin >> a[i];

    for (int i = 0; i < e; ++i) {
        string x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0, c; i < v; ++i) {
        cin >> c;

        colors[a[i]] = c;
        usedColors.insert(c);
    }

    auto findColor = [&](string u) {
        unordered_set<int> occupied;

        for (auto x : g[u])
            if (colors[x] != -1)
                occupied.insert(colors[x]);

        for (auto x : usedColors)
            if (!occupied.count(x))
                return x;

        for (int i = 0;; ++i)
            if (!occupied.count(i))
                return i;
    };

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (colors[s] != -1) {
            bool isGood = all_of(g[s].begin(), g[s].end(), [&](auto x) {
                return colors[x] != colors[s];
            });

            if (isGood)
                cout << "TRUE" << endl;
            else
                colors[s] = -1;
        }

        if (colors[s] == -1) {
            int c = findColor(s);

            colors[s] = c;
            cout << c << endl;
        }
    }
}