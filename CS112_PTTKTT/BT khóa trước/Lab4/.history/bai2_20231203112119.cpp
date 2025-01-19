#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> dup;

bool checkValidIP(string s, vector<bool> res)
{
    int t = 0;

    for (int i = 0; i < res.size(); ++i) {
        t = t * 10 + (s[i] - '0');

        if (res[i]) {
            if (t > 255)
                return false;

            t = 0;
        }
    }

    return t <= 255;
}

void find(int startIndex, int& total, string s, vector<bool>& res)
{
    // 0123456789 -> neu chen tai i = 2 -> 012.3456789
    for (int i = startIndex; i < s.length(); i++) {
        // chi can i tai vi tri cuoi thi khong xet nua, vi khong the them dau . cuoi cung
        if (i == s.size() - 1) {
            if (total == 0 && checkValidIP(s, res)) {
                string res = "";

                for (int k = 0; k < res.size(); ++k) {
                    res += s[k];

                    if (res[k])
                        res += ".";
                }

                if (dup.find(res) == dup.end()) {
                    dup[res] = true;
                    cout << res << "\n";
                }

                cout << "\n";
            }

            break;
        } else {
            if (total > 0) {
                // choose or not choose
                int prev = res[i];

                for (int j = 0; j <= 1; ++j) {
                    res[i] = j;
                    total -= j;

                    find(i + 1, total, s, res);

                    total += j;
                    res[i] = prev;
                }
            } else {
                find(i + 1, total, s, res);
                break;
            }
        }
    }
}

int main()
{
    string s;
    getline(cin, s);

    vector<bool> res(s.length());
    int total = 3;

    find(0, total, s, res);
}