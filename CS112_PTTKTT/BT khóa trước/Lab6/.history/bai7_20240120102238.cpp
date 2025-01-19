#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> page, price;
vector<vector<int>> dp;

int find(int i, int cur)
{
    if (i == n)
        return 0;

    if (dp[i][cur] != -1)
        return dp[i][cur];

    if (cur + price[i] <= x)
        return dp[i][cur] = max(
                   page[i] + find(i + 1, cur + price[i]),
                   find(i + 1, cur));

    return dp[i][cur] = find(i + 1, cur);
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

    for (int i = 0; i <= x; ++i) {
        if (i + price[n - 1] <= x) {
            dp[n - 1][i] = page[n - 1];
        } else {
            dp[n - 1][i] = 0;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= x; ++j) {
            if (j + price[i] <= x) {
                dp[i][j] = max(dp[i + 1][j], page[i] + dp[i + 1][j + price[i]]);
            } else {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }

    cout << dp[0][0];
}