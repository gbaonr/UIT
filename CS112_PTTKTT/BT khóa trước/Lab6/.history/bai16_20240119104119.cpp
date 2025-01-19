#include <bits/stdc++.h>
using namespace std;

pair<int, int> moves[] = {
    { -1, 0 },
    { 0, -1 },
    { -1, -1 }
};

int main()
{
    int m, n, x1, y1, x2, y2;
    cin >> m >> n >> x1 >> y1 >> x2 >> y2;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[m - i - 1][j];
        }
    }

    x1 = m - x1 - 1;
    x2 = m - x2 - 1;

    vector<vector<int>> dp(m, vector<int>(n));
    queue<pair<int, int>> q;

    q.push({ x1, y1 });
    while (q.size()) {
        auto [x, y] = q.front();

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 0; ++j) {
                int xx = x + i;
                int yy = y + j;

                if (xx >= 0 && yy >= 0 && xx < m && yy < n && a[xx][yy] == 0) {
                    dp[xx][yy] = min(dp[xx][yy], dp[x][y] + 1);
                    q.push({ xx, yy });
                }
            }
        }
    }

    // dp[x1][y1] = 0;

    // for (int i = m - 1; i >= 0; --i) {
    //     for (int j = 0; j < n; ++j) {
    //         if (a[i][j]) {
    //             dp[i][j] = -1;
    //             continue;
    //         }

    //         for (auto& move : moves) {
    //             int x = i + move.first;
    //             int y = j + move.second;

    //             if (x >= 0 && y >= 0 && x < m && y < n && a[x][y] == 0) {
    //                 dp[i][j] = min(dp[i][j], dp[x][y] + 1);
    //             }
    //         }
    //     }
    // }

    // cout << dp[0][n - 1];
}