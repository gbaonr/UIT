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

    return (yy > 0) && (mm > 0 && mm <= 12) && (dd > 0 && dd <= 31)
        && (((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) && dd <= 31)
            || ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd <= 30)
            || (mm == 2 && yy % 4 == 0 && dd <= 29)
            || (mm == 2 && yy % 4 != 0 && dd <= 28));
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