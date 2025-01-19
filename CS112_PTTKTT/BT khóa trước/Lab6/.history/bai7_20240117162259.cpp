#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> page, price;
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

    price.resize(n);
    page.resize(n);
    dp.resize(n, vector<int>(x + 1, -1));

    for (auto& v : price)
        cin >> v;

    for (auto& v : page)
        cin >> v;

    // cout << find(0, 0);
}