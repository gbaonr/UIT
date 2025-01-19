#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e, n; // so dinh, so canh, so luong dinh can xet
    cin >> v >> e >> n;

    vector<string> a(v); // chua danh sach ten cac dinh
    unordered_map<string, vector<string>> g; // chua danh sach ke cua cac dinh ~O(1)
    unordered_map<string, int> colors; // chua mau cua cac dinh ~O(1)
    set<int> usedColors; // chua cac mau da su dung, su dung set de check mau trung lap trong O(log n)

    for (int i = 0; i < v; ++i)
        cin >> a[i]; // nhap ten dinh

    for (int i = 0; i < e; ++i) {
        string x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0, c; i < v; ++i) {
        cin >> colors[a[i]]; // gan mau cho dinh a[i]

        if (c != -1)
            usedColors.insert(c); // luu lai cac mau da duoc su dung
    }

    // khoi tao mot ham de to mau
    auto findColor = [&](string u) {
        // danh sach chua cac mau da duoc to o cac dinh ke cua u
        unordered_set<int> occupied;

        for (auto x : g[u])
            if (colors[x] != -1)
                occupied.insert(colors[x]); // them mau vao danh sach

        // xet tung mau da duoc su dung, neu mau do chua duoc to
        // o cac dinh lien ke --> to mau do
        for (auto x : usedColors)
            if (!occupied.count(x))
                return x;

        // truong hop tat cac mau deu da su dung --> khoi tao mot mau moi
        for (int i = 0;; ++i)
            if (!occupied.count(i))
                return i;
    };

    // xu ly tung dinh can xet
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s; // nhap dinh can xet
        bool isGood = false;

        // neu chua duoc to mau
        if (colors[s] != -1) {
            isGood = all_of(g[s].begin(), g[s].end(), [&](auto x) {
                return colors[x] != colors[s];
            });

            if (isGood)
                cout
                    << "TRUE" << endl;
        }

        if (!isGood) {
            int c = findColor(s);
            cout << c << endl;
        }
    }
}