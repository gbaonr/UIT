#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    string s, d;
    cin >> s >> d;

    vector<string> vertex(v);
    for (auto& x : vertex) {
        cin >> x;
    }

    map<string, int> cost;
    for (auto& x : vertex) {
        cin >> cost[x];
    }

    map<string, map<string, int>> g;
    for (int i = 0; i < e; ++i) {
        string u, v;
        int w;
        cin >> u >> v >> w;

        g[u][v] = w;
    }

    auto astar = [&]() {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        pq.push({ 0, s });
    }
}