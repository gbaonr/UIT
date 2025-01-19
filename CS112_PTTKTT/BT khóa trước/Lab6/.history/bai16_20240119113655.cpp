#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, x1, y1, x2, y2;
    cin >> m >> n >> x1 >> y1 >> x2 >> y2;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // cin >> a[m - i - 1][j];
            cin >> a[i][j];
        }
    }

    // x1 = m - x1 - 1;
    // x2 = m - x2 - 1;

    cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";

    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    vector<vector<bool>> used(m, vector<bool>(n));
    queue<pair<int, int>> q;

    q.push({ x1, y1 });
    dp[x1][y1] = 0;

    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == x2 && y == y2) {
            break;
        }

        if (used[x][y])
            continue;

        used[x][y] = true;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) 
                    continue;

                int xx = x + i;
                int yy = y + j;

                if (xx >= 0 && yy >= 0 && xx < m && yy < n) {
                    if (a[xx][yy] == 0) {
                        dp[xx][yy] = min(1 + dp[x][y], dp[xx][yy]);
                        q.push({ xx, yy });
                    }
                }
            }
        }
    }

    cout << (dp[x2][y2] == INT_MAX ? -1 : dp[x2][y2]);
}