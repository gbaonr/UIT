#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<pair<int, int>> v(n);
vector<vector<int>> dp;

int find(int i, int cur)
{
    if (i == n)
        return 0;

    if (~dp[i][cur])
        return dp[i][cur];

    int res = 0;

    if (cur + v[i].first <= x) {
        res = find(i + 1, cur);
        res = max(res, v[i].second + find(i + 1, cur + v[i].first));
        return dp[i][cur] = res;
    } else {

    }

    return dp[i][cur] = res;
}

int main()
{
    cin >> n >> x;

    v.resize(n);
    dp.resize(n, vector<int>(x + 1, -1));

    for (auto& t : v)
        cin >> t.first;

    for (auto& t : v)
        cin >> t.second;

    sort(v.begin(), v.end());
    cout << find(0, 0);
}