#include <bits/stdc++.h>
using namespace std;

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