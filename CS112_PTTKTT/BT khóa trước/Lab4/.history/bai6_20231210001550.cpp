#include <bits/stdc++.h>
using namespace std;

void dfs(int u)
{
}

int main()
{
    int n;
    string s;
    cin >> n >> s;

    map<string, map<string, int>> m;
    map<string, int> d;

    for (int i = 0; i < n; i++) {
        string u, v;
        int w;

        cin >> u >> v >> w;
        m[u][v] = w;
    }
}