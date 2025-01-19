#include <bits/stdc++.h>
using namespace std;

int find(int i, int cur)
{
    if (i == n)
        return 0;

    if (~dp[i][cur])
        return dp[i][cur];

    int res = 0;

    if (cur + price[i] <= x)
        res = page[i] + find(i + 1, cur + price[i]);

    res = max(res, find(i + 1, cur));

    return dp[i][cur] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v(n);
    vector<vector<int>> dp(x + 1, vector<int>(n + 1));

    for (auto& t : v)
        cin >> t.first;

    for (auto& t : v)
        cin >> t.second;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= x; ++j) {
            if (j - v[])
        }
    }

    cout << dp[x][n];
}