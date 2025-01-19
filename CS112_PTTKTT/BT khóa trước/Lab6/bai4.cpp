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
        // khoi tao gia tri dp[i] cho truong hop i <= 6 
        if (i <= 6)
            res[i] += 1; 

        // tinh dp[i], su dung max(i - j, 0) de trong truong hop i < j
        // ta su dung res[0] = 0 (khong co dong gop cho dp[i])
        res[i] += res[max(i - 1, 0)] + res[max(i - 2, 0)]
            + res[max(i - 3, 0)] + res[max(i - 4, 0)]
            + res[max(i - 5, 0)] + res[max(i - 6, 0)];

        res[i] %= 1000000007;
    }

    // xuat ket qua la so cach lac xi ngau tong la s
    cout << res[s];
}