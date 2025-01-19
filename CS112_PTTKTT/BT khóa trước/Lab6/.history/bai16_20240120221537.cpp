#include <bits/stdc++.h>
using namespace std;

int main()
{
    // nhap kich thuoc ma tran
    int m, n, x1, y1, x2, y2;
    cin >> m >> n >> x1 >> y1 >> x2 >> y2;

    // ma tran do thi giua cac diem
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;

            // vi de la 1 nghia la khong duoc di qua, 0 nghia la duoc di qua
            // nen ta doi nguoc lai gia tri de weight cua canh la 1 khi duoc di qua
            a[i][j] = 1 - x;
        }
    }

    // vi toa do cua ma tran bat dau tu goc duoi ben trai
    // nen ta doi nguoc lai theo toa do chuan (goc tren ben trai la (0, 0))
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

            // cout << dist << " " << x << " " << y << "\n";

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

                    if (u < 0 || u >= m || v < 0 || v >= n) {
                        continue;
                    }

                    auto w = a[u][v];

                    if (w == 0)
                        continue;

                    if (!close[u][v]) {
                        if (open[u][v] && g[x][y] + w >= g[u][v]) {
                            continue;
                        }

                        // cout << "u = " << u << " v = " << v << " " << x << " " << y << "\n";

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

                        // cout << "u = " << u << " v = " << v << " " << x << " " << y << "\n";
                        pq.push({ f[u][v], u, v });

                        open[u][v] = 1;
                        close[u][v] = 0;
                    }
                }
            }
        }

        if (!found) {
            cout << "-1";
            return;
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

    astar();
}