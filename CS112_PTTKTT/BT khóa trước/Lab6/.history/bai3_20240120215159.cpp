#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e; // so dinh, so canh
    cin >> v >> e; // nhap so dinh va so canh

    vector<string> a(v); // chua ten cac dinh
    unordered_map<string, vector<string>> g; // chua danh sach ke cua cac dinh
    unordered_map<string, int> colors_ver; // chua mau cua cac dinh
    unordered_set<int> colors; // chua cac mau da duoc su dung

    // nhap cac dinh va khoi tao mau cac dinh chua duoc to mau
    for (int i = 0; i < v; ++i) {
        cin >> a[i];
        colors_ver[a[i]] = -1;
    }

    // nhap do thi
    for (int i = 0; i < e; ++i) {
        string u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    // vi de yeu cau xuat mau theo danh sach ban dau cua -> clone a
    vector<string> b(a);

    // sap xep cac dinh theo thu tu giam dan so dinh ke
    sort(a.begin(), a.end(), [&](string u, string v) {
        return g[u].size() > g[v].size();
    });

    // duyet cac dinh sau khi da sap xep
    for (auto u : a) {
        // dung de luu cac mau da duoc su dung o dinh ke voi u
        unordered_set<int> usedColors;

        // xet tung dinh ke voi u
        for (auto v : g[u])
            if (colors_ver[v] != -1)
                usedColors.insert(colors_ver[v]); // neu v da to mau --> them mau vao usedColors

        // su dung de biet khi nao can them mau moi
        bool foundColor = false;

        // duyet qua kho mau
        for (auto c : colors) {
            // neu mau c chua duoc su dung o dinh ke voi u
            if (!usedColors.count(c)) {
                colors_ver[u] = c; // to mau c cho u
                foundColor = true; // thong bao da tim thay mau
                break;
            }
        }

        // neu khong tim thay mau --> them mau moi
        if (!foundColor) {
            for (int i = 0;; ++i) // duyet tu 0 -> vo cung
                if (!colors.count(i)) { // neu i chua duoc su dung
                    colors_ver[u] = i; // to mau i cho u
                    colors.insert(i);
                    break;
                }
        }
    }

    // xuat mau cac dinh theo thu tu ban dau
    for (auto u : b)
        cout << colors_ver[u] << " ";
}