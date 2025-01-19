#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto& v : a)
        cin >> v;

    sort(a.begin(), a.end());

    vector<bool> dp(accumulate(a.begin(), a.end(), 0) + 1, false);
    vector<int> g(accumulate(a.begin(), a.end(), 0) + 1, -1);

    // a[i]   = 2 2 4 5
    // sum    = 13
    // res    = {  0,  0, 1, 0,  1, 1, 0,  0,  0,  0,  0,  0,  0,  0 }
    // g      = { -1, -1, 0, 0, -1, 2, 3, -1, -1, -1, -1, -1, -1, -1 }
    for (int i = 0; i < a.size(); i++) {
        dp[a[i]] = true;

        if (g[a[i]] != -1)
            g[a[i]] = min(g[a[i]], i);
        else
            g[a[i]] = i;
    }

    // i la cac gia tri co the dat duoc
    for (int i = 1; i < dp.size(); i++) {
        // xet tung gia tri trong a
        for (int j = 0; j < a.size(); j++) {
            // neu i < a[j], tuc la khong the dat duoc gia tri i
            // neu su dung gia tri a[j] -> co the bo qua
            if (i < a[j])
                continue;

            // i = x + a[j] // vi the ta can xem xet cac gia tri x = i - a[j]
            // last[i - a[j]] la vi tri cuoi cung duoc dungf de tao ra i - a[j]
            // kiem tra j > last[i - a[j]] tranh xay trung lap nhu 2 + 4 va 4 + 2
            if (j <= g[i - a[j]])
                continulaste;

            // neu gia tri i - a[j] co the tao ra duoc
            if (dp[i - a[j]]) {
                dp[i] = true; // thi i cung co the tao ra duoc
                g[i] = j; // va vi tri cuoi cung duoc dung de tao ra i la j (vi tri cua a[j])
            }
        }
    }

    cout << accumulate(dp.begin(), dp.end(), 0) << endl;
    for (int i = 0; i < dp.size(); i++)
        if (dp[i])
            cout << i << " ";

    cout << endl;
    for (int i = 0; i < dp.size(); i++)
        if (dp[i])
            cout << g[i] << " ";
}