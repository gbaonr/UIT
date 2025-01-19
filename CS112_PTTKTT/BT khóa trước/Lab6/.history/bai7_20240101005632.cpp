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

    if (cur + price[i] <= x)
        res = page[i] + find(i + 1, cur + price[i]);

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
    // for (int i = 0; i < n; i++)
    //     v[i] = { price[i], page[i] };

    cout << find(0, 0);
}