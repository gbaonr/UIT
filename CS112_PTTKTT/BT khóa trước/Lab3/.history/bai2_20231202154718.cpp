#include <bits/stdc++.h>
using namespace std;

int main()
{
    int e;
    string s;

    cin >> e >> s;

    map<string, map<string, int>> graph;
    set<string> vertices;

    for (int i = 0; i < e; ++i) {
        string u, v;
        int w;

        cin >> u >> v >> w;
        graph[u][v] = w;
        vertices.insert(u);
    }

    while (graph.size()) {
        for (auto it = graph[s].begin(); it != graph[s].end(); ++it) {

        }
    }
}