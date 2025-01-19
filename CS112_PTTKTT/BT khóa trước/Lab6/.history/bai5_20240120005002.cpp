#include <bits/stdc++.h>
using namespace std;

int main()
{
    // kich thuoc ban do
    int n;
    cin >> n;

    // ma tran chua cac ki tu mo ta duong di
    char a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    // ma tran (n + 1) x (n + 1) chua so duong di toi moi vi tri (i, j)
    // n + 1 vi xet duong di tu (1, 1) den (n, n)
    // dp[0][...] va dp[...][0] deu bang 0 --> co the su dung de khoi dung if
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    if (a[1][1] == '*' || a[n][n] == '*')
        // neu vi tri (1, 1) hoac (n, n) la vat can --> khong co duong di
        // cac cong thuc truy hoi sau se luon luon co gia tri dp[i][j] = 0
        dp[1][1] = 0;
    else
        // nguoc lai thi luon co cach di
        dp[1][1] = 1;

    // xet tung dong, tu tren xuong duoi
    for (int i = 1; i <= n; i++) {
        // xet tung cot, tu trai qua phai
        for (int j = 1; j <= n; j++) {
            // neu la vat can --> thi ta co the bo qua, dp[i][j] luc nay se van la 0
            if (a[i][j] == '*')
                continue;

            // nguoc lai, thi so duong di toi vi tri (i, j) la tong so duong di toi
            // (i - 1, j) va (i, j - 1)
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1];

            // do ket qua co the rat lon --> lay dong du 10^9 + 7
            dp[i][j] %= 1000000007;
        }
    }

    // xuat ket qua la so duong di toi vi tri (n, n)
    // neu khong co duong di --> dp[n][n] = 0
    cout << dp[n][n];
}