#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    string s, d;
    cin >> s >> d;

    vector<string> vertices(v);
    for (auto& x : vertices) {
        cin >> x;
    }

    unordered_map<string, int> cost;
    for (auto& x : vertices) {
        cin >> cost[x];
    }

    unordered_map<string, map<string, int>> g;
    for (int i = 0; i < e; ++i) {
        string u, v;
        int w;
        cin >> u >> v >> w;

        g[u][v] = w;
    }

    auto astar = [&]() {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        unordered_map<string, int> close, open, g, f;
        unordered_map<string, string> prev;

        for (auto& x : vertices) {
            close[x] = 0;
        }

        pq.push({ 0, s });
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();

            if (u == d) {
                return dist;
            }

            for (auto &v : vertices) {
                auto w = g[u][v];

                if (w == 0)
                    continue;

                if (!close[v] && !open[v]) {
                    g[v] = g[u] + w;
                    f[v] = g[v] + cost[v];
                    prev[v] = u;
                    pq.push({ f[v], v });
                    open[v] = 1;
                }

                if (close[v] && open[v] && g[v] > g[u] + w) {
                    g[v] = g[u] + w;
                    f[v] = g[v] + cost[v];
                    prev[v] = u;
                    pq.push({ f[v], v });
                    open[v] = 1;
                }

                if (close[v] && g[v] > g[u] + w) {
                    g[v] = g[u] + w;
                    f[v] = g[v] + cost[v];
                    prev[v] = u;
                    pq.push({ f[v], v });
                    open[v] = 1;
                    close[v] = 0;
                }
            }
        }
    }
}