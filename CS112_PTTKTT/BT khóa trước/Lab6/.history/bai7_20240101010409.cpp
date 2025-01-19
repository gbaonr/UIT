#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<pair<int, int>> v(n);
vector<vector<int>> dp;

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

    cin >> n >> x;

    v.resize(n);
    dp.resize(n, vector<int>(x + 1, -1));

    for (auto& t : v)
        cin >> t.first;

    for (auto& t : v)
        cin >> t.second;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= x; j++) {
            if (j + v[i].first <= x) {
                dp[i][j] = max(dp[i + 1][j], v[i].second + dp[i + 1][j + v[i].first]);
            } else {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }

    sort(v.begin(), v.end());
    cout << find(0, 0);
}