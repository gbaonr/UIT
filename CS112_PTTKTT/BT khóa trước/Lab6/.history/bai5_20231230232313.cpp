#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    long long res[n + 1][n + 1] = { 0 };
    res[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '*')
                continue;

            res[i][j] = res[max(i - 1, 0)][j] + res[i][max(j - 1, 0)];
            res[i][j] %= 1000000007;
        }
    }

    cout << res[n][n];
}