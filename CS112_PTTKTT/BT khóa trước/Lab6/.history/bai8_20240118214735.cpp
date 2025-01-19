#include <bits/stdc++.h>
using namespace std;

/*
- Them: them gia tri m[j] --> j + 1
- Thay the: thay n[i] = m[j] --> i + 1, j + 1
- Xoa: xoa n[i] --> i + 1
*/

string a, b;

int dpFunc(int i, int j)
{
    if (i == a.size() || j == b.size()) {
        if (i == a.size())
            return b.size() - j;
        else
            return a.size() - i;
    }

    if (a[i] == b[j]) {
        return dpFunc(i + 1, j + 1);
    }

    return 1 + min({ dpFunc(i + 1, j), dpFunc(i, j + 1), dpFunc(i + 1, j + 1) });
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
    cout << dpFunc(0, 0);
}