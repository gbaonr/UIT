#include <bits/stdc++.h>
using namespace std;

int main()
{
    int e;
    string s;

    cin >> e >> s;

    map<string, map<string, int>> graph;

    for (int i = 0; i < e; ++i) {
        string u, v;
        int w;

        cin >> u >> v >> w;
        graph[u][v] = w;
    }

}