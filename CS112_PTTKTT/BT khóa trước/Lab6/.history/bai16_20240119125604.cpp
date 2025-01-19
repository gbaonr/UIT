#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, x1, y1, x2, y2;
    cin >> m >> n >> x1 >> y1 >> x2 >> y2;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;

            a[m - i - 1][j] = 1 - x;
        }
    }

    x1 = m - x1 - 1;
    x2 = m - x2 - 1;

    auto astar = [&]() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> open, g, f;
        unordered_map<int, int> prev;
        vector<vector<int>> close(m, vector<int>(n, 0));

        auto found = false;

        pq.push({ 0, { x1, x2 } });
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
    }
}