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
        string candicate;
        int minWeight = INT_MAX;

        for (auto it = graph[s].begin(); it != graph[s].end(); ++it) {
            if (vertices.find(it->first) != vertices.end()) {
                if (it->second < minWeight) {
                    minWeight = it->second;
                    candicate = it->first;
                }
            }  
        }
    }
}