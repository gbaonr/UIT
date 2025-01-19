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
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        unordered_map<int, int> prev;
        vector<vector<int>> close(m, vector<int>(n, 0)), open(m, vector<int>(n, 0)), g(m, vector<int>(n)), f(m, vector<int>(n));

        auto found = false;

        pq.push({ 0, x1, x2 });
        while (!pq.empty()) {
            auto [dist, x, y] = pq.top();
            pq.pop();
            close[x][y] = 1;

            if (x == x2 && y == y2) {
                found = true;
                break;
            }

            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    if (i == 0 && j == 0)
                        continue;

                    auto u = x + i;
                    auto v = y + j;
                    auto w = 1;

                    if (u < 0 || u >= m || v < 0 || v >= n)
                        continue;

                    if (!close[u][v]) {
                        if (open[u][v] && g[x][y] + w >= g[v]) {
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
}