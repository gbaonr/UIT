#include <bits/stdc++.h>
using namespace std;

int n, W;
vector<int> w, p;
vector<long long> dp;

// int dpFunc(int i, int total)
// {
//     if (i == n)
//         return 0;

//     if (total + w[i] > W)
//         return dpFunc(i + 1, total);

//     return max(dpFunc(i + 1, total), dpFunc(i + 1, total + w[i]) + p[i]);
// }

int main()
{
    cin >> n >> W;

    w.assign(n, 0);
    p.assign(n, 0);

    for (int i = 0; i < n; ++i)
        cin >> w[i] >> p[i];

    // N = 100
    // W_i = 10^5
    // N * (W_i * N) = 10^9 * 4 = 3G

    int total = accumulate(w.begin(), w.end(), 0);
    W = min(W, total)

    dp.assign(total + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= total; ++j) {
            if (j + w[i] <= W) {
                dp[j] = max(dp[j], p[i] + dp[j + w[i]]);
            }
        }
    }

    cout << dp[0];
}