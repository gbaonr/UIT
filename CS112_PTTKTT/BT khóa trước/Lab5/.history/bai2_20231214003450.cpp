#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numV, e;
    cin >> numV >> e;

    string _s, _d;
    cin >> _s >> _d;

    map<string, int> l2i;
    map<int, string> i2l;
    for (int i = 0; i < numV; ++i) {
        string u;
        cin >> u;

        l2i[u] = i;
        i2l[i] = u;
    }

    int s = l2i[_s];
    int d = l2i[_d];

    vector<int> cost(numV);
    for (auto& x : cost) {
        cin >> x;
    }

    unordered_map<int, map<int, int>> graph;
    for (int i = 0; i < e; ++i) {
        string u, v;
        int w;
        cin >> u >> v >> w;

        graph[l2i[u]][l2i[v]] = w;
    }

    auto astar = [&]() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> close, open, g, f;
        unordered_map<int, int> prev;

        auto found = false;

        for (int i = 0; i < numV; ++i) {
            close[i] = 0;
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

            for (int v = 0; v < numV; ++v) {
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
                    open[v] = 1;

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

        int c = d;
        vector<string> path;
        int dist = 0;

        while (c != s) {
            path.push_back(i2l[c]);
            dist += graph[prev[c]][c];
            c = prev[c];
        }
        path.push_back(i2l[s]);

        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << " \n"[i == 0];
        }

        cout << totalClosed << " " << dist << endl;
    };

    astar();
}