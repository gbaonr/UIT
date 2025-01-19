#include <bits/stdc++.h>
using namespace std;

int n, x; // so luong sach, gioi han tien co the mua

vector<int> page, price; // page[i] la so trang cua sach thu i
                         // price[i] la gia tien cua sach thu i

vector<vector<int>> dp; // dp[i][j] la so trang lon nhat co the dat duoc
                        // khi xet tu n - 1 den i, va j la so tien da dung

// ham quay lui, voi i la vi tri sach dang xet
// cur la tong gia tien cac sach da mua
int find(int i, int cur)
{
    // dieu kien dung sau khi da xet het tat ca cac sach
    if (i == n)
        return 0;

    // neu them sach hiem hoi thu i vao gio hang van khong vuot qua x
    if (cur + price[i] <= x)
        // ta se lay thu ca hai cach,
        // dong thoi chon ra cach cho ket qua tot nha
        return max(
            page[i] + find(i + 1, cur + price[i]), // thu mua sach thu i
            find(i + 1, cur) // thu khong mua sach thu i
        );

    // truong hop khong the them sach thu i vao gio hang
    // --> ta chi co the chon cach khong mua sach thu i
    // va tim kiem tiep cac sach tiep theo
    return find(i + 1, cur);
}

int main()
{
    cin >> n >> x;

    price.resize(n);
    page.resize(n);
    dp.resize(n, vector<int>(x + 1, -1));

    // nhap gia tien
    for (auto& v : price) cin >> v;

    // nhap so trang
    for (auto& v : page)
        cin >> v;

    // khoi tao gia tri ban dau cho dp
    for (int i = 0; i <= x; ++i) {
        if (i + price[n - 1] <= x) {
            dp[n - 1][i] = page[n - 1];
        } else {
            dp[n - 1][i] = 0;
        }
    }

    // xet sach thu i tu n - 2 den 0, bo qua sach thu n - 1 vi da xet o tren
    for (int i = n - 2; i >= 0; --i) {
        // xet cac gia tri tien da su dung tu 0 den x
        for (int j = 0; j <= x; ++j) {
            // neu mua sach thu i, nhung tong gia tien khong vuot qua x
            if (j + price[i] <= x) {
                // thu ca hai cach, dong thoi chon ra cach cho ra so trang lon nhat
                dp[i][j] = max(dp[i + 1][j], page[i] + dp[i + 1][j + price[i]]);
            } else {
                // chi co the khong mua sach thu i, va su dung ket qua cua 
                // lan xet sach truoc do
                dp[i][j] = dp[i + 1][j];
            }
        }
    }

    // xuat ra ket qua la so trang lon nhat co the dat duoc
    cout << dp[0][0];
}