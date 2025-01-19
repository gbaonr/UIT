#include <bits/stdc++.h>
using namespace std;

int main()
{
    // nhap kich thuoc ma tran
    int m, n, x1, y1, x2, y2;
    cin >> m >> n >> x1 >> y1 >> x2 >> y2;

    // ma tran do thi giua cac diem
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;

            // vi de la 1 nghia la khong duoc di qua, 0 nghia la duoc di qua
            // nen ta doi nguoc lai gia tri de weight de cho thuan tien
            a[i][j] = 1 - x;
        }
    }

    for (auto& v : a) {
        for (auto& u : v) {
            cout << u << " ";
        }
        cout << "\n";
    }

    // vi toa do cua ma tran bat dau tu goc duoi ben trai
    // nen ta doi nguoc lai theo toa do chuan (goc tren ben trai la (0, 0))
    x1 = m - x1 - 1;
    x2 = m - x2 - 1;

    // dinh nghia thuat toan A*
    auto astar = [&]() {
        // su dung priority queue de luu cac dinh, va lay ra dinh co f nho nhat
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        vector<vector<int>> close(m, vector<int>(n)), // danh dau cac dinh da duoc xet
            open(m, vector<int>(n)), // danh dau cac dinh dang duoc xet
            g(m, vector<int>(n)), // luu gia tri g cua cac dinh
            f(m, vector<int>(n)); // luu gia tri f cua cac dinh

        // luu toa do dinh truoc do cua dinh hien tai
        vector<vector<pair<int, int>>> prev(m, vector<pair<int, int>>(n));

        // su dung de xem neu co duong den vi tri cong chua
        auto found = false;

        // them dinh bat dau vao priority queue
        pq.push({ 0, x1, y1 });

        // trong khi con dinh chua xet
        while (!pq.empty()) {
            // lay ra dinh co f nho nhat
            // <f(x, y), x, y>
            auto [dist, x, y] = pq.top();
            pq.pop();
            
            cout << x << " " << y << " " << dist << "\n";

            close[x][y] = 1; // danh dau dinh dang xet

            // neu da tim thay duong den vi tri cong chua
            if (x == x2 && y == y2) {
                found = true;
                break;
            }

            // xet cac huong di chuyen
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    if (i == 0 && j == 0) // khong xet huong di dung yen
                        continue;

                    auto u = x + i;
                    auto v = y + j;

                    // neu toa do u, v khong nam trong ma tran
                    if (u < 0 || u >= m || v < 0 || v >= n) {
                        continue;
                    }

                    auto w = a[u][v];

                    // neu ko the di qua u, v khong the di qua
                    if (w == 0)
                        continue;

                    // neu diem lang gieng u, v chua duoc xet
                    if (!close[u][v]) {
                        // neu diem lang gieng u, v da duoc duoc open de xet
                        // nhung duong di hien tai co gia tri f lon hon duong di truoc do
                        // thi bo qua
                        if (open[u][v] && g[x][y] + w >= g[u][v]) {
                            continue;
                        }

                        // cap nhat gia tri g cho diem lang gieng u, v
                        // = gia tri g cua diem hien tai + 1 
                        // vi diem lang gieng cach diem hien tai 1 don vi
                        g[u][v] = g[x][y] + 1;
                        f[u][v] = g[u][v]; // khong can su dung ham heuristic
                        prev[u][v] = { x, y }; // luu toa do dinh truoc do cua u, v de truy vet
                        open[u][v] = 1; 
                        pq.push({ f[u][v], u, v }); // them u, v vao priority queue
                    }

                    // neu diem lang gieng u, v da duoc xet
                    // nhung duong di hien tai co gia tri f nho hon duong di truoc do
                    if (close[u][v] && g[x][y] + w < g[u][v]) {
                        // van cap nhat giong nhu tren
                        g[u][v] = g[x][y] + 1;
                        f[u][v] = g[u][v];
                        prev[u][v] = { x, y };

                        pq.push({ f[u][v], u, v });

                        open[u][v] = 1;
                        close[u][v] = 0;
                    }
                }
            }
        }

        // neu khong tim thay duong di
        if (!found) {
            cout << "-1";
            return;
        }

        // truy vet duong di, (x, y) la toa do cua vi tri cong chua
        auto x = x2, y = y2;

        // so canh gio can di chuyen
        int total = 0;

        while (x != x1 || y != y1) {
            auto [u, v] = prev[x][y]; // lay toa do dinh truoc do cua x, y

            x = u;
            y = v;
            total++;
        }

        cout << total << "\n";
    };

    astar();
}