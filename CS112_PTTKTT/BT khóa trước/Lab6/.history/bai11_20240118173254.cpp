#include <bits/stdc++.h>
using namespace std;

int n, W;
vector<int> w, p;
vector<vector<int>> dp;

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

    dp.assign(total + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= total; ++j) {
            if (j + w[i] <= W) {
                dp[i][j] = max(dp[i + 1][j], p[i] + dp[i + 1][j + w[i]]);
            } else {
                dp[i][j] = dp[i + 1][j];
            }
        }
    }

    cout << dp[0][0];
}