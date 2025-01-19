#include <bits/stdc++.h>
using namespace std;

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
    for (int i = startIndex; i < s.size(); i++) {
        // chi can i tai vi tri cuoi thi khong xet nua, vi khong the them dau . cuoi cung
        if (i == s.size() - 1) {
            if (total == 0 && checkValidIP(s, res)) {
                for (int k = 0; k < res.size(); ++k) {
                    cout << s[k];

                    if (res[k])
                        cout << ".";
                }
            }
        } else {
            if (total > 0) {
                // choose or not choose
                for (int j = 0; j <= 1; ++j) {
                    res[i] = j;
                    total -= j;

                    find(i + 1, total, s, res);

                    total += j;
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
    cin >> s;
}