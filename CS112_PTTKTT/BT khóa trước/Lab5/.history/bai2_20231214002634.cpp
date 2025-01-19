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

    unordered_map<string, map<string, int>> graph;
    for (int i = 0; i < e; ++i) {
        string u, v;
        int w;
        cin >> u >> v >> w;

        graph[u][v] = w;
    }

    auto astar = [&]() {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        unordered_map<string, int> close, open, g, f;
        unordered_map<string, string> prev;

        auto found = false;

        for (auto& x : vertices) {
            close[x] = 0;
        }

        pq.push({ 0, s });
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();
            close[u] = 1;

            if (u == d) {
                found = true;
                break;
            }

            for (auto& v : vertices) {
                auto w = graph[u][v];

                if (w == 0)
                    continue;

                if (!close[v]) {
                    if (open[v] && g[u] + w >= g[v]) {
                        continue;
                    }

                    g[v] = g[u] + w;
                    f[v] = g[v] + cost[v];
                    prev[v] = u;
                    open[v] = 1;
                    pq.push({ f[v], v });
                }

                if (close[v] && g[u] + w < g[v]) {
                    g[v] = g[u] + w;
                    f[v] = g[v] + cost[v];
                    prev[v] = u;
                    pq.push({ f[v], v });

                    // xoa dinh khoi close
                    close[v] = 0;
                }
            }
        }

        int totalClosed = accumulate(close.begin(), close.end(), 0, [](int acc, auto& x) {
            return acc + x.second;
        });

        if (!found) {
            cout << "-unreachable-" << endl;
            cout << totalClosed << " " << 0 << endl;
            return;
        }

        string c = d;
        vector<string> path;
        int dist = 0;

        while (c != s) {
            path.push_back(c);
            dist += graph[prev[c]][c];
            c = prev[c];
        }
        path.push_back(s);

        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << " \n"[i == 0];
        }

        cout << totalClosed << " " << dist << endl;
    };

    astar();
}