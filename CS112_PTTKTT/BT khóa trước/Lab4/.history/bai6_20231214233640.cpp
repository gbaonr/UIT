#include <bits/stdc++.h>
using namespace std;

unordered_map<string, map<string, int>> graph;
unordered_map<string, bool> visited;
int n;
string s;

void find(int idx, int total, string s, string d)
{
    for (auto [v, w] : graph[s]) {
        if (visited[v])
            continue;

        if (v == d && idx == graph.size() - 1) {
            cout << idx << " " << w << endl;
            return;
        }

        visited[v] = true;
        total += w;
        find(idx + 1, total v, d);
        total -= w;
        visited[v] = false;
    }
}

int main()
{
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        string u, v;
        int w;

        cin >> u >> v >> w;
        graph[u][v] = w;
        visited[u] = false;
        visited[v] = false;
    }

    find(0, s, s);
}