#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[m - 1][0] = 0;

    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j < n; --j) {
            if (j != n - 1 && i != 0) {
                dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j + 1]);
            }
        }
    }
}