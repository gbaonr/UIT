#include <bits/stdc++.h>
using namespace std;

void check(vector<bool>& res)
{
    long long t = 0;
}

// max length = 35
// it nhat 3 so => moi so toi da 12 chu so

void check(vector<bool>& res, string& s)
{
    for (int i = 0; i < res.size(); ++i) {
        // cout << s[i];

        // if (res[i] == 1) {
        //     cout << " + ";
        // }
    }

    // cout << '\n';
}

void find(int startIndex, string& s, int len, long long prev1, long long prev2, long long cur, vector<bool>& res)
{
    for (int i = startIndex; i < s.size(); ++i) {
        if (i == s.size() - 1) {
            check(res, s);
        } else {
            int tcur = cur * 10 + (s[i + 1] - '0');

            for (int j = 0; j <= 1; ++j) {
                if (j == 1) {
                    int prev = res[i];
                    res[i] = 1;

                    find(i + 1, s, 1, prev2, tcur, 0, res);

                    res[i] = prev;
                } else {
                    // khong chen
                    if (len + 1 > ceil(s.size() / 3.0)) {
                        return;
                    }

                    if (tcur > prev1 + prev2) {
                        return;
                    }

                    find(i + 1, s, len + 1, prev1, prev2, tcur, res);
                }
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;

    vector<bool> res(s.size(), 0);
    int cur = 0;

    find(0, s, 1, LONG_LONG_MAX, LONG_LONG_MAX, cur, res);
}