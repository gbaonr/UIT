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