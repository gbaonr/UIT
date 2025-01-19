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

    dp[0] = a[0][2];
    for (int i = 1; i < n; i++) {
        int l = 0, r = i - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (get<1>(a[mid]) < get<0>(a[i]))
                l = mid + 1;
            else
                r = mid;
        }

        if (get<1>(a[l]) < get<0>(a[i]))
            dp[i] = max(dp[i - 1], dp[l] + get<2>(a[i]));
        else
            dp[i] = max(dp[i - 1], get<2>(a[i]));
    }
}