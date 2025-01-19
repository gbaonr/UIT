#include <bits/stdc++.h>
using namespace std;

map<string, map<string, int>> m;
map<string, vector<string>> vm;
map<string, map<string, int>> r; // reverse graph
map<string, vector<string>> vr;
map<string, int> d;

void dfs(string u)
{
    for (auto v : vr[u]) {

    }
}

int main()
{
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        string u, v;
        int w;

        cin >> u >> v >> w;
        m[u][v] = w;
        r[v][u] = w;
        vm[u].push_back(v);
        vr[v].push_back(u);
    }
}