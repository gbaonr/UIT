#include <bits/stdc++.h>
using namespace std;

int find(int i, int cur, vector<pair<int, int>>& v, vector<vector<int>>& dp, int n, int x)
{
    if (i == n)
        return 0;

    if (~dp[i][cur])
        return dp[i][cur];

    int res = 0;

    if (cur + v[i].first <= x) {
        res = find(i + 1, cur, v, dp, n, x);
        res = max(res, v[i].second + find(i + 1, cur + v[i].first, v, dp, n, x));
        return dp[i][cur] = res;
    }

    return dp[i][cur] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v(n);
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));

    for (auto& t : v)
        cin >> t.first;

    for (auto& t : v)
        cin >> t.second;

    sort(v.begin(), v.end());

    for (int i = n - 1; i >= 0; i--) {

    }

    cout << find(0, 0, v, dp, n, x);
}