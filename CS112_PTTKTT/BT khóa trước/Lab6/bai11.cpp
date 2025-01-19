#include <bits/stdc++.h>
using namespace std;

int n, W;
vector<int> w, p;
vector<long long> dp;

// int dpFunc(int i, int total)
// {
//     if (i == n)
//         return 0;

//     if (total + w[i] > W)
//         return dpFunc(i + 1, total);

//     return max(dpFunc(i + 1, total), dpFunc(i + 1, total + w[i]) + p[i]);
// }

int main()
{
    // nhap n va W
    cin >> n >> W;

    // nhap w[i] va p[i]
    w.;
    p.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> w[i] >> p[i];

    // tinh tong trong luong cac do vat
    int total = accumulate(w.begin(), w.end(), 0);

    // W la trong luong toi da co the mang
    W = min(W, total);

    // khoi tao vector dp co kich thuoc la total + 1
    dp.assign(total + 1, 0);

    // xet cac do vat tu n - 1 -> 0
    for (int i = n - 1; i >= 0; --i) {
        // j tu 0 -> total hay total -> 0 deu duoc
        // tai vi cac ket qua dp[i] truoc do su dung o day 
        // deu la cua do vat thu i + 1  
        for (int j = 0; j <= total; ++j) {

            // neu j + w[i] <= W, tuc la co the chua duoc do vat i
            if (j + w[i] <= W) {
                // o day ta co the chon hoac khong chon do vat i
                // neu khong chon do vat i, ta se lay ket qua truoc do khi xet toi i + 1
                // neu chon do vat i, ta se lay ket qua dp[j + w[i]] + p[i]
                // lay max de cho ra ket qua lon nhat
                dp[j] = max(dp[j], p[i] + dp[j + w[i]]);
            }
        }
    }

    cout << dp[0];
}