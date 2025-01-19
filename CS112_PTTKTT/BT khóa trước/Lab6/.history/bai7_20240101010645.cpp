#include <bits/stdc++.h>
using namespace std;

// int find(int i, int cur)
// {
//     if (i == n)
//         return 0;

//     if (~dp[i][cur])
//         return dp[i][cur];

//     int res = 0;

//     if (cur + v[i].first <= x) {
//         res = find(i + 1, cur);
//         res = max(res, v[i].second + find(i + 1, cur + v[i].first));
//         return dp[i][cur] = res;
//     }

//     return dp[i][cur] = res;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    vector<pair<int, int>> v(n);
    vector<vector<int>> dp;

    cin >> n >> x;

    v.resize(n);
    dp.resize(n, vector<int>(x + 1, -1));

    for (auto& t : v)
        cin >> t.first;

    for (auto& t : v)
        cin >> t.second;

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        for (int cur = 0; cur <= x; cur++) {
            if (i == 0) {
                if (cur >= v[i].first)
                    dp[i][cur] = v[i].second;
                else
                    dp[i][cur] = 0;

                continue;
            }

            dp[i][cur] = dp[i - 1][cur];

            if (cur >= v[i - 1].first) {
                dp[i][cur] = max(dp[i][cur], v[i - 1].second + dp[i - 1][cur - v[i - 1].first]);
            }
        }
    }

    // cout << find(0, 0);
    cout << dp[n - 1][x];
}