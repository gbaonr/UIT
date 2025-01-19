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
    vector<vector<bool>> used(m, vector<bool>(n));
    queue<pair<int, int>> q;

    q.push({ x1, y1 });
    cout << x1 << " " << y1 << "\n";

    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();

        if (used[x][y])
            continue;

        if (x == x2 && y == y2) {
            break;
        }

        used[x][y] = true;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int xx = x + i;
                int yy = y + j;

                if (xx >= 0 && yy >= 0 && xx < m && yy < n && !used[xx][yy]) {
                    if (a[xx][yy] == 0) {
                        dp[xx][yy] = 1 + dp[x][y];
                        cout << "update " << xx << " " << yy << " " << dp[xx][yy] << "\n";
                        q.push({ xx, yy });
                    } else {
                        dp[xx][yy] = -1;
                    }
                }
            }
        }
    }

    cout << dp[x2][y2];

    cout << "\n";
    // cout << dp[2][0] << " " << dp[1][1] << " " << dp[0][2] << " " << dp[1][0] << " " << dp[0][1] << " " << dp[0][0] << "\n";
    cout << dp[1][1] << " " << dp[0][2] << " " << dp[1][0] << " " << dp[0][1] << " " << dp[0][0] << "\n";
}