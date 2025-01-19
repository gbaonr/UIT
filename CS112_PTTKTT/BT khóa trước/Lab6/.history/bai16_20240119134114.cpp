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
            // a[i][j] = 1 - x;
        }
    }

    x1 = m - x1 - 1;
    x2 = m - x2 - 1;

    auto astar = [&]() {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<int>> close(m, vector<int>(n)), open(m, vector<int>(n)), g(m, vector<int>(n)), f(m, vector<int>(n));
        vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m));

        auto found = false;

        pq.push({ 0, x1, y1 });
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

                    if (u < 0 || u >= m || v < 0 || v >= n)
                        continue;

                    cout << u << " " << v << "\n";
                    auto w = a[u][v];
                    cout << close[u][v] << " " << open[u][v] << " " << g[u][v] << " " << g[x][y] << prev[u][v].first << " " << w << "\n";
                    cout << w << "\n";

                    if (w == 0)
                        continue;

                    if (!close[u][v]) {
                        if (open[u][v] && g[x][y] + w >= g[u][v]) {
                            continue;
                        }

                        g[u][v] = g[x][y] + w;
                        f[u][v] = g[u][v];
                        prev[u][v] = { x, y };
                        open[u][v] = 1;
                        pq.push({ f[u][v], u, v });
                    }

                    if (close[u][v] && g[x][y] + w < g[u][v]) {
                        g[u][v] = g[x][y] + w;
                        f[u][v] = g[u][v];
                        prev[u][v] = { x, y };

                        pq.push({ f[u][v], u, v });

                        open[u][v] = 1;
                        close[u][v] = 0;
                    }
                }
            }
        }

        auto x = x2, y = y2;
        int total = 0;

        while (x != x1 || y != y1) {
            auto [u, v] = prev[x][y];

            x = u;
            y = v;
            total++;
        }

        cout << total << "\n";
    };

    cout << "x1 = " << x1 << " y1 = " << y1 << "\n";
    cout << "x2 = " << x2 << " y2 = " << y2 << "\n";
    astar();
}