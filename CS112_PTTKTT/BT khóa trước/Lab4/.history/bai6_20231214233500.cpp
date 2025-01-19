#include <bits/stdc++.h>
using namespace std;

unordered_map<string, map<string, int>> graph;
unordered_map<string, bool> visited;
int n;
string s;

void find(int idx, string s, string d)
{
    for (auto [v, w] : graph[s]) {
        if (visited[v])
            continue;

        if (v == d) {
            cout << idx << " " << w << endl;
            return;
        }

        visited[v] = true;
        find(idx + 1, v, d);
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