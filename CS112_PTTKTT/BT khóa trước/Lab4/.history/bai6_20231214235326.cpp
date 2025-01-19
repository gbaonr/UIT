#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, unordered_map<string, int>> graph;
unordered_map<string, bool> visited;
vector<string> path;
int n;
string s, res;
int minCost = 2e9;

void find(int idx, int total, string s, string d)
{
    for (auto [v, w] : graph[s]) {
        if (visited[v])
            continue;

        if (v == d && idx == graph.size() - 1) {
            total += w;

            if (total < minCost) {
                minCost = total;
                res = "";
                for (int i = 0; i < path.size(); i++) {
                    res += path[i] + " ";
                }
                res += d;
                // cout << minCost << " " << res << endl;
            }

            return;
        }

        visited[v] = true;
        total += w;

        if (total < minCost && idx < graph.size())
            find(idx + 1, total, v, d);

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

    path.assign(graph.size(), "");

    find(0, 0, s, s);

    cout << res << endl;
}