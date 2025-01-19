#include <bits/stdc++.h>
using namespace std;
bool check[10];
set<vector<string>> res;
map<string, int> mp;
string s = "        ";
bool check_ngay(string y, string m, string d)
{
    int yy = stoi(y);
    int mm = stoi(m);
    int dd = stoi(d);
    int max_d;
    bool nam_nhuan = 0;
    if (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0))
        nam_nhuan == 1;
    switch (mm) {
    case 1:
    case 5:
    case 3:
    case 8:
    case 7:
    case 12:
    case 10:
        max_d = 31;
        break;
    case 2:
        if (yy % 3328 == 0)
            max_d = 30;
        else if (nam_nhuan)
            max_d = 29;
        else
            max_d = 28;
        break;
    default:
        max_d = 30;
        break;
    }
    if (mm <= 0 || yy <= 0 || dd <= 0)
        return false;
    if (dd > max_d)
        return false;
    if (mm > 12)
        return false;
    return true;
}
void Try_y(int i, string y)
{
    for (int j = 0; j < y.length(); j++) {
        if (!check[j]) {
            s[i] = y[j];
            check[j] = 1;
            if (i == 7) {
                string y = s.substr(0, 4);
                string m = s.substr(4, 2);
                string d = s.substr(6, 2);
                string temp = y + ' ' + m + ' ' + d + ' ';
                vector<string> t(3, "");
                if (check_ngay(y, m, d) && mp[temp] != 1) {
                    t[0] = y;
                    t[1] = m;
                    t[2] = d;
                    res.insert(t);
                    mp[temp] = 1;
                }
            }

            else
                Try_y(i + 1, y);
            check[j] = 0;
        }
    }
}

int main()
{
    string dates = "";
    string tmp;

    cin >> tmp;
    datas += tmp;
    cin >> tmp;
    datas += tmp;
    cin >> tmp;
    datas += tmp;

    string t;
    for (int i = 0; i < dates.length(); i++) {
        if (dates[i] != ' ') {
            t.push_back(dates[i]);
        }
    }
    Try_y(0, t);
    cout << res.size() << '\n';
    for (auto i : res) {
        cout << i[0] << " " << i[1] << " " << i[2] << '\n';
    }
    return 0;
}