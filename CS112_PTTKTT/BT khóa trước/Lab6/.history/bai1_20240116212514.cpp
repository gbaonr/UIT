#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e, n;
    cin >> v >> e >> n;

    vector<string> a(v);
    unordered_map<string, vector<string>> g;
    unordered_map<string, int> colors;

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
    }

    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
    }
}