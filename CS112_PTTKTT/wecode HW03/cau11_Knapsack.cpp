#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n, W;
    cin >> n >> W;
    // vector<vector<long long>> table(n + 1, vector<long long>(W + 1)); // table[vat thu i][max size tui]
    vector<long> table(W + 1, 0);
    vector<long> w(n + 1);
    vector<long> v(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    // for (auto it : table)
    //     cout << it << " ";
    // cout << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = W; j >= 1; j--)
        {
            if (j >= w[i])
            {
                table[j] = max(table[j], table[j - w[i]] + v[i]);
            }
        }

        // cout << "w" << i << ", v" << i << " :    ";
        // for (auto it : table)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;
    }

    cout << table[W] << endl;

    // for (auto it : table)
    //     cout << it << " ";
    return 0;
}