#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<int, int, int>> a;
vector<int> nextProject;

long long dpFunc(int i)
{
    if (i == n)
        return 0;

    // => neu chon project i thi phai bo qua cac project con lai
    if (nextProject[i] == -1) {
        // cout << "skip: " << i << " " << dpFunc(i + 1) << endl;
        return max(dpFunc(i + 1), (long long) get<2>(a[i]));
    }

    auto t = dpFunc(i + 1);
    cout << "no choose: " << i << " " << t << endl;
    // cout << "choose: " << i << " " << get<2>(a[i]) + dpFunc(nextProject[i]) << endl;
    // cout << endl;

    return max(dpFunc(i + 1), get<2>(a[i]) + dpFunc(nextProject[i]));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;

    for (int i = 0, x, y, z; i < n; i++) {
        cin >> x >> y >> z;
        a.push_back({ x, y, z });
    }

    sort(a.begin(), a.end(), [](auto& l, auto& r) {
        return get<1>(l) < get<1>(r);
    });

    nextProject.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (get<0>(a[j]) > get<1>(a[i])) {
                nextProject[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << nextProject[i] << ' ';
    }

    // cout << dpFunc(0);
    vector<long long> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        if (nextProject[i] == -1) {
            dp[i] = max(dp[i + 1], (long long)get<2>(a[i]));
        } else {
            dp[i] = max(dp[i + 1], dp[nextProject[i]] + (long long)get<2>(a[i]));
        }
    }

    cout << dp[0] << "\n";
    cout << dpFunc(0);
}