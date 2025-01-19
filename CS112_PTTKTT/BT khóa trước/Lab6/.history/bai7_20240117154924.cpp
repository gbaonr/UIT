#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v(n);
    vector<vector<int>> dp(x, vector<int>(n));

    for (auto& t : v)
        cin >> t.first;

    for (auto& t : v)
        cin >> t.second;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {

        }
    }
}