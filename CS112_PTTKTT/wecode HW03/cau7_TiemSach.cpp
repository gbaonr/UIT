#include <vector>
#include <iostream>

using namespace std;

int main()
{

    long n, X;
    cin >> n >> X;
    vector<int> price(n);      // h
    vector<int> pages(n);      // s
    vector<long> table(X + 1); // table[i] = max pages co the mua duoc voi gia tien i

    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    // duyet qua tung cuon sach
    for (int i = 0; i < n; i++)
    {
        // duyet nguoc gia tien tu X -> 1 (gia tri cua j-w[i] chua bi thay doi khi lay max o buoc thu j)
        for (int j = X; j >= 1; j--)
        {
            if (j >= price[i])
            {
                table[j] = max(table[j], table[j - price[i]] + pages[i]);
            }
        }
    }

    cout << table[X] << endl;

    // for (auto it : table)
    // {
    //     cout << it << " ";
    // }
    return 0;
}