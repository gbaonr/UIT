#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s;
    cin >> s;

    // khoi tao mang dp[i] chua so cach de tung
    long long res[max(s + 1, 7)] = { 0 };

    // tinh cac gia tri dp[i]
    for (int i = 1; i <= s; i++) {
        if (i <= 6)
            res[i] += 1;

        res[i] += res[max(i - 1, 0)] + res[max(i - 2, 0)]
            + res[max(i - 3, 0)] + res[max(i - 4, 0)]
            + res[max(i - 5, 0)] + res[max(i - 6, 0)];

        res[i] %= 1000000007;
    }

    cout << res[s];
}