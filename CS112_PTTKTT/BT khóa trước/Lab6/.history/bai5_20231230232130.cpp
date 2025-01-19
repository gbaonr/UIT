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

    long long res[n][n] = { 0 };
    res[0][0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            res[i][j]
            //     res[i][j] += res[i - 1][j];

            // if (j > 0)
            //     res[i][j] += res[i][j - 1];

            // res[i][j] %= 1000000007;
        }
}