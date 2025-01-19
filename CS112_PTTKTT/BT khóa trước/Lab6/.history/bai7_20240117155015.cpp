#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v(n);
    vector<vector<int>> dp(x + 1, vector<int>(n));

    for (auto& t : v)
        cin >> t.first;

    for (auto& t : v)
        cin >> t.second;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            if (j >= v[i - 1].first) {
                dp[j][i] = max(dp[j][i - 1], dp[j - v[i - 1].first][i - 1] + v[i - 1].second);
            } else {
                dp[j][i] = dp[j][i - 1];
            }
        }
    }

    cout << dp[x][n];
}