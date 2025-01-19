#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v(n);
    vector<int> dp(x);

    for (auto& t : v)
        cin >> t.first;

    for (auto& t : v)
        cin >> t.second;

    dp[0] = 0;
    for (int i = 1; i <= x; ++i) {
        for (auto& t : v) {
            if (i - t.first >= 0) {
                dp[i] = max(dp[i], dp[i - t.first] + t.second);
            }
        }
    }
}