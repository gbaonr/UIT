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

bool check(string y, string m, string d) {
    int yy = stoi(y);
    int mm = stoi(m);
    int dd = stoi(d);

    if (yy < 1900 || yy > 2019)
        return false;

    if (mm < 1 || mm > 12)
        return false;

    if (dd < 1 || dd > 31)
        return false;

    if (mm == 2) {
        if (yy % 4 == 0 && yy % 100 != 0 || yy % 400 == 0) {
            if (dd > 29)
                return false;
        } else {
            if (dd > 28)
                return false;
        }
    }

    if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
        if (dd > 30)
            return false;
    }

    return true;
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

    for (auto& v : py) {
        cout << v << '\n';
    }
}