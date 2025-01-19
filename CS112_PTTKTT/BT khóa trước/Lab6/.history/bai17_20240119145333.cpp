#include <bits/stdc++.h>
using namespace std;

pair<int, int> moves[] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

int cost(int x1, int y1, int x2, int y2)
{
    if (x1 == x2 || y1 == y2) {
        return 0;
    }

    return 1;
}

int main()
{
    int m, n, x1, y1, x2, y2;
    cin >> m >> n >> x1 >> y1 >> x2 >> y2;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;

            a[i][j] = 1 - x;
        }
    }

    x1 = m - x1 - 1;
    x2 = m - x2 - 1;

    auto astar = [&]() {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<int>> close(m, vector<int>(n)), open(m, vector<int>(n)), g(m, vector<int>(n)), f(m, vector<int>(n));
        vector<vector<pair<int, int>>> prev(m, vector<pair<int, int>>(n));

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

            for (auto move : moves) {
                auto [i, j] = move;
                if (i == 0 && j == 0)
                    continue;

                auto u = x + i;
                auto v = y + j;

                if (u < 0 || u >= m || v < 0 || v >= n) {
                    continue;
                }

                if (a[u][v] == 0)
                    continue;

                // auto w = cost(u, v, x2, y2) + 1;
                auto w = 1;
                // auto w = a[u][v];

                // if (w == 0)
                //     continue;

                if (!close[u][v]) {
                    if (open[u][v] && g[x][y] + w >= g[u][v]) {
                        continue;
                    }

                    g[u][v] = g[x][y] + w;
                    f[u][v] = g[u][v] + cost(u, v, x2, y2);
                    prev[u][v] = { x, y };
                    open[u][v] = 1;
                    pq.push({ f[u][v], u, v });
                }

                if (close[u][v] && g[x][y] + w < g[u][v]) {
                    g[u][v] = g[x][y] + w;
                    f[u][v] = g[u][v] + cost(u, v, x2, y2);
                    prev[u][v] = { x, y };

                    pq.push({ f[u][v], u, v });

                    open[u][v] = 1;
                    close[u][v] = 0;
                }
            }
        }

        if (!found) {
            cout << "-1";
            return;
        }

        auto x = x2, y = y2;
        int total = 0;

        // cout << f[x1][y1] << "\n";
        // cout << g[x1][y1] << "\n";
        // cout << f[x2][y2] << "\n";
        // cout << g[x2][y2] << "\n";

        vector<vector<int>> res(m, vector<int>(n));
        res[x2][y2] = 1;

        while (x != x1 || y != y1) {
            auto [u, v] = prev[x][y];

            x = u;
            y = v;
            res[x][y] = 1;
            total++;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; j++) {
                if (res[i][j])
                    cout << "x";
                else {
                    cout << "_";
                }
            }

            cout << "\n";
        }

        cout << total << "\n";
    };

    astar();
}