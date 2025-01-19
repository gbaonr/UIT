#include <bits/stdc++.h>
using namespace std;

void permutation(int cur, string s, string& temp, vector<string>& res, vector<bool>& used)
{
    for (int i = 0; i < s.size(); ++i) {
        if (used[i])
            continue;

        used[i] = true;
        temp[cur] = s[i];

        if (cur == s.size() - 1) {
            res.push_back(temp);
        } else {
            permutation(cur + 1, s, temp, res, used);
        }

        used[i] = false;
    }
}

bool check(string y, string m, string d)
{
    int yy = stoi(y);
    int mm = stoi(m);
    int dd = stoi(d);

    if (yy < 0 || mm < 0 || dd < 0 || mm > 12 || dd > 31)
        return false;

    if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
        return dd <= 31;
    } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
        return dd <= 30;
    } else {
        if (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)) {
            return dd <= 29;
        } else if (yy % 3328 == 0) {
            return dd <= 30;
        } else {
            return dd <= 28;
        }
    }
}

int main()
{
    string y, m, d;
    cin >> y >> m >> d;

    string ty = "    ";
    string tm = "  ";
    string td = "  ";

    vector<string> py, pm, pd;
    vector<bool> uy(4), um(2), ud(2);

    permutation(0, y, ty, py, uy);
    permutation(0, m, tm, pm, um);
    permutation(0, d, td, pd, ud);

    set<tuple<string, string, string>> res;
    for (auto& y : py) {
        for (auto& m : pm) {
            for (auto& d : pd) {
                if (check(y, m, d)) {
                    res.push_back({ y, m, d });
                }
            }
        }
    }

    sort(res.begin(), res.end(), [](tuple<string, string, string> a, tuple<string, string, string> b) {
        int ya = stoi(get<0>(a));
        int yb = stoi(get<0>(b));
        int ma = stoi(get<1>(a));
        int mb = stoi(get<1>(b));
        int da = stoi(get<2>(a));
        int db = stoi(get<2>(b));

        if (ya != yb)
            return ya < yb;

        if (ma != mb)
            return ma < mb;

        return da < db;
    });

    for (auto& x : res) {
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << '\n';
    }
}