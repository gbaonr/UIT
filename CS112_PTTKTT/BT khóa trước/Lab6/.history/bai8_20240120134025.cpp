#include <bits/stdc++.h>
using namespace std;

/*
- Them: them gia tri m[j] --> j + 1
- Thay the: thay n[i] = m[j] --> i + 1, j + 1
- Xoa: xoa n[i] --> i + 1
*/

string a, b;

// i la index cua n,
// j la index cua m
int find(int i, int j)
{
    // neu xet toi phan tu cuoi cung cua n hoac m
    if (i == a.size() || j == b.size()) {
        if (i == a.size())
            // neu i la vi tri cuoi cung cua n -> chi can them cac phan tu con lai cua m
            return b.size() - j;
        else
            // nguoc lai, neu j la vi tri cuoi cung cua m -> chi can xoa cac phan tu con lai cua n
            return a.size() - i;
    }

    if (a[i] == b[j]) {
        return find(i + 1, j + 1);
    }

    return 1 + min({ find(i + 1, j), find(i, j + 1), find(i + 1, j + 1) });
}

int main()
{
    cin >> a >> b;

    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));

    for (int i = 0; i <= a.size(); ++i)
        dp[i][b.size()] = a.size() - i;

    for (int i = 0; i <= b.size(); ++i)
        dp[a.size()][i] = b.size() - i;

    for (int i = a.size() - 1; i >= 0; --i) {
        for (int j = b.size() - 1; j >= 0; --j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i + 1][j + 1];
            } else {
                dp[i][j] = 1 + min({ dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1] });
            }
        }
    }

    cout << dp[0][0];
}