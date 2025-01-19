#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int size1 = s1.size();
    int size2 = s2.size();

    // table[i][j] = chi phi bien chuoi do dai i thanh chuoi do dai j
    vector<vector<int>> table(size1 + 1, vector<int>(size2 + 1, 0));

    // can i buoc de bien chuoi rong thanh chuoi co do dai i
    for (int i = 0; i <= size1; i++)
        table[i][0] = i;

    // can i buoc de bien chuoi do dai i thanh chuoi rong
    for (int i = 0; i <= size2; i++)
        table[0][i] = i;

    for (int i = 1; i <= size1; i++)
    {
        for (int j = 1; j <= size2; j++)
        {
            // ki tu thu i-1 giong nhau -> ko can thay doi -> table[i][j] = table[i-1][j-1]
            if (s1[i - 1] == s2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1];
            }
            else
            {
                // min(xoa, thay the, them)
                table[i][j] = 1 + min(table[i - 1][j], min(table[i - 1][j - 1], table[i][j - 1]));
            }
        }
    }

    // // print dp table
    // for (auto i : table)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    cout << table[size1][size2];

    return 0;
}