#include <bits/stdc++.h>
using namespace std;

int main()
{
    // nhap n va cac gia tri x[i]
    int n; cin >> n;
    vector<int> x(n);

    for (auto& v : x) cin >> v;

    // khoi tao vector dp va g, co kich thuoc bang tong cac gia tri x[i]
    // dp[i] mac dinh la false
    // g[i] mac dinh la -1
    vector<bool> dp(accumulate(x.begin(), x.end(), 0) + 1, false);
    vector<int> g(accumulate(x.begin(), x.end(), 0) + 1, -1);


    // sap xep cac gia tri x[i] theo thu tu tang dan
    sort(x.begin(), x.end());


    // a[i]   = 2 2 4 5
    // sum    = 13
    // res    = {  0,  0, 1, 0,  1, 1, 0,  0,  0,  0,  0,  0,  0,  0 }
    // g      = { -1, -1, 0, 0, -1, 2, 3, -1, -1, -1, -1, -1, -1, -1 }
    for (int i = 0; i < x.size(); i++) {
        dp[x[i]] = true;

        if (g[x[i]] != -1)
            g[x[i]] = min(g[x[i]], i);
        else
            g[x[i]] = i;
    }

    // i la cac gia tri co the dat duoc
    for (int i = 1; i < dp.size(); i++) {
        // xet tung gia tri trong a
        for (int j = 0; j < x.size(); j++) {
            // neu i < a[j], tuc la khong the dat duoc gia tri i
            // neu su dung gia tri a[j] -> co the bo qua
            if (i < x[j])
                continue;

            // i = x + a[j] // vi the ta can xem xet cac gia tri x = i - a[j]
            // last[i - a[j]] la vi tri cuoi cung duoc dungf de tao ra i - a[j]
            // kiem tra j > last[i - a[j]] tranh xay trung lap nhu 2 + 4 va 4 + 2
            if (j <= g[i - x[j]])
                continue;

            // neu gia tri i - a[j] co the tao ra duoc
            if (dp[i - x[j]]) {
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