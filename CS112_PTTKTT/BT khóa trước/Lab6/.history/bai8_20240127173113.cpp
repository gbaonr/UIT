#include <bits/stdc++.h>
using namespace std;

/*
- Them: them gia tri m[j] --> j + 1
- Thay the: thay n[i] = m[j] --> i + 1, j + 1
- Xoa: xoa n[i] --> i + 1
*/


// i la index cua n,
// j la index cua m
int find(int i, int j)
{
    // neu xet toi phan tu cuoi cung cua n hoac m
    if (i == a.size() || j == b.size()) {
        if (i == a.size())
            // neu i la vi tri cuoi cung cua n -> chi can them cac phan tu con lai cua m
            return b.size() - j;
        else
            // nguoc lai, neu j la vi tri cuoi cung cua m -> chi can xoa cac phan tu con lai cua n
            return a.size() - i;
    }

    // neu n[i] == m[j] --> khong can thay doi gi ca
    // xet tiep cac phan tu tiep theo
    if (a[i] == b[j])
        return find(i + 1, j + 1);

    // neu n[i] != m[j] --> ta co the thuc hien 1 trong 3 hanh dong
    return 1 + min({ 
        find(i + 1, j),  // xoa n[i] -> xet tiep cac phan tu con lai cua n
        find(i, j + 1),  // them m[j] vao truoc n[i] -> i khong doi, xet tiep cac phan tu con lai cua m
        find(i + 1, j + 1)  // thay the n[i] = m[j] -> xet tiep cac phan tu con lai cua n va m
    });
}

int main()
{
    // nhap 2 chuoi
    string n, m; cin >> n >> m;

    // khoi tao vector dp, co kich thuoc (n + 1) x (m + 1)
    vector<vector<int>> dp(n.size() + 1, vector<int>(m.size() + 1));

    // khoi tao gia tri ban dau cho dp khi i = n.size() hoac j = m.size()
    for (int i = 0; i <= n.size(); ++i)
        dp[i][m.size()] = n.size() - i;

    for (int i = 0; i <= m.size(); ++i)
        dp[n.size()][i] = m.size() - i;

    // tinh cac gia tri cho dp[i][j]
    // moi xet , ta xet tu cuoi len dau cua tung chuoi
    for (int i = n.size() - 1; i >= 0; --i) {
        for (int j = m.size() - 1; j >= 0; --j) {
            if (n[i] == m[j]) {
                // neu n[i] == m[j] --> khong can thay doi gi ca
                dp[i][j] = dp[i + 1][j + 1];
            } else {
                // neu n[i] != m[j] --> ta co the thuc hien 1 trong 3 hanh dong
                // chon ra hanh dong co ket qua tot nhat
                dp[i][j] = 1 + min({ dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1] });
            }
        }
    }

    // xuat ket qua la so thao tac it nhat de bien chuoi n thanh chuoi m
    cout << dp[0][0];
}