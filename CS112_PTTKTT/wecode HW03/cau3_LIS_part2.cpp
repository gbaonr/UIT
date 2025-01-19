#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long> a(n);        // mang luu cac gia tri
    vector<int> m(n, 0);      // mang luu chuoi con tang lon nhat toi phan tu thu i
    vector<int> trace(n, -1); // luu gia tri cuoi trong chuoi con tang dai nhat
    m[0] = 1;
    int max_idx = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // dynamic planning
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] and m[i] < m[j] + 1)
            {
                m[i] = m[j] + 1;
                trace[i] = j;
            }
        }
        m[i] = (m[i] == 0) ? 1 : m[i];
        if (m[i] > m[max_idx])
        {
            max_idx = i;
        }
    }

    // for (auto it : trace)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    // for (auto it : m)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    // cout << "max_idx = " << max_idx << ", a[max_idx] = " << a[max_idx] << ", trace[max_idx] = " << trace[max_idx] << endl;

    // cout << endl
    //      << endl
    //      << endl;

    vector<int> res;
    while (max_idx != -1)
    {
        // cout << a[max_idx] << " ";
        res.insert(res.begin(), a[max_idx]);
        max_idx = trace[max_idx];
    };
    // res.insert(res.begin(), a[max_idx]);
    cout << res.size() << endl;
    for (auto r : res)
    {
        cout << r << " ";
    }
}