#include <bits/stdc++.h>
using namespace std;

int n; // so do an
vector<tuple<int, int, int>> a; // list cac do an <bat dau, ket thuc, so tin>
vector<int> nextProject; // nextProject[i] = j => project tiep theo cua i la project j (thoa dieu kien thoi gian)

long long dpFunc(int i)
{
    if (i == n)
        return 0;

    // => neu chon project i thi phai bo qua cac project con lai
    if (nextProject[i] == -1) {
        return max(dpFunc(i + 1), 1LL * get<2>(a[i]));
    }

    return max(dpFunc(i + 1), get<2>(a[i]) + dpFunc(nextProject[i]));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;

    // nhap cac do an
    for (int i = 0, x, y, z; i < n; i++) {
        cin >> x >> y >> z;
        a.push_back({ x, y, z });
    }

    // sap xep cac do an theo thoi gian bat dau tang dan
    sort(a.begin(), a.end(), [](auto& l, auto& r) {
        return get<0>(l) < get<0>(r);
    });

    nextProject.assign(n + 1, -1);

    // su dung thuat toan chat nhi phan de tim project tiep theo cua moi project
    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(a.begin(), a.end(), a[i], [](auto& l, auto& r) {
            return get<1>(l) < get<0>(r);
        });

        nextProject[i] = it - a.begin(); // index cua du an tiep theo
    }

    vector<long long> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        if (nextProject[i] == -1) {
            dp[i] = max(dp[i + 1], 1LL * get<2>(a[i]));
        } else {
            dp[i] = max(dp[i + 1], dp[nextProject[i]] + get<2>(a[i]));
        }
    }

    cout << dp[0] << "\n";
    // cout << dpFunc(0);
}