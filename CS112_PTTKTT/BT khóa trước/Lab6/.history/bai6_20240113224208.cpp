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

    vector<vector<int>> dp(n, vector<int>(2, 0));

    // khoi tao dp[0] la do an dau tien
    dp[0] = get<2>(a[0]);

    for (int i = 1; i < n; i++) {
        int start = get<0>(a[i]);

        // su dung binary search de tim do an truoc do ma thoi gian ket thuc nho hon thoi gian bat dau cua do an hien tai
        int l = 0, r = i - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (get<1>(a[mid]) < start)
                l = mid + 1;
            else
                r = mid;
        }

        dp[i] = max(dp[i - 1], get<2>(a[i]) + dp[l]);
        cout << "start: " << start << " l: " << l << endl;
    }
}