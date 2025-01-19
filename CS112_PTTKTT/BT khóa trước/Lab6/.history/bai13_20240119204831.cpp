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

    for (int i = 0; i < v; ++i) cin >> a[i]; // nhap ten dinh

    for (int i = 0; i < e; ++i) {
        string x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0, c; i < v; ++i) {
        cin >> c;

        colors[a[i]] = c;

        if (c != -1)
            usedColors.insert(c);
    }

    auto findColor = [&](string u) {
        unordered_set<int> occupied;

        for (auto x : g[u])
            if (colors[x] != -1)
                occupied.insert(colors[x]);

        for (auto x : usedColors)
            if (!occupied.count(x))
                return x;

        for (int i = 0;; ++i)
            if (!occupied.count(i))
                return i;
    };

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        bool isGood = false;

        if (colors[s] != -1) {
            isGood = all_of(g[s].begin(), g[s].end(), [&](auto x) {
                return colors[x] != colors[s];
            });
            [isGood = all_of(g[s].begin(), g[s].end(), [&](auto x) { trả về màu[x] != màu[s]; });] x

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