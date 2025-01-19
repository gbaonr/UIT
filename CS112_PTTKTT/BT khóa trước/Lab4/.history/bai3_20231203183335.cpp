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
}