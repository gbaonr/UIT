#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> map(n, vector<char>(n));
    vector<vector<long long>> a(n, vector<long long>(n, 0));
    long long MOD = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    if (map[0][0] == '.')
        a[0][0] = 1;

    // cout << "\nDP:" << endl;
    // for (auto i : a)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == '*')
            {
                a[i][j] = 0;
            }
            else
            {
                if (i > 0)
                {
                    a[i][j] += a[i - 1][j];
                }
                if (j > 0)
                {
                    a[i][j] += a[i][j - 1];
                }

                a[i][j] = a[i][j] % MOD;
            }
        }
    }

    // cout << "\nDP after:" << endl;
    // for (auto i : a)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << "        ";
    //     }
    //     cout << endl;
    // }

    cout << a[n - 1][n - 1];
}