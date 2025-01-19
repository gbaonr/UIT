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

    if (cur + v[i].first <= x)
        res = v[i].second + find(i + 1, cur + v[i].first);

    res = max(res, find(i + 1, cur));

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

    // sort price and page in ascending order of price
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    cout << find(0, 0);
}