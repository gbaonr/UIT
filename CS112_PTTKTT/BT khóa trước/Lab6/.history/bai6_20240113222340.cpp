#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> a;

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a.push_back({ x, y, z });
    }

    sort(a.begin(), a.end(), [](auto& l, auto& r) {
        return get<1>(l) < get<1>(r);
    });

    for (int i = 0; i < n; i++) {
        cout << get<0>(a[i]) << " " << get<1>(a[i]) << " " << get<2>(a[i]) << endl;
    }

    vector<int> dp(n);

    // khoi tao dp[0] la do an dau tien
    dp[0] = get<2>(a[0]);

    for (int i = 1; i < n; i++) {
        start = get<0>(a[i]);
    }
}