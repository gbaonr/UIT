#include <bits/stdc++.h>
using namespace std;

int countNumber(int t)
{
    int count = 0;

    while (t > 0) {
        count++;
        t /= 10;
    }

    return count;
}

bool checkValidIP(string s, vector<bool> res)
{
    int t = 0;
    int len = 0;

    for (int i = 0; i < res.size(); ++i) {
        t = t * 10 + (s[i] - '0');
        len++;

        cout << countNumber(t) << " " << t << "\n";

        if (t > 255 || len > 3 || countNumber(t) != len)
            return false;

        if (res[i]) {
            if (t > 255)
                return false;

            t = 0;
            len = 0;
        }
    }

    return t <= 255 && len > 0 && len <= 3;
}

void find(int startIndex, int& total, string s, vector<bool>& res, unordered_map<string, bool>& dup)
{
    // 0123456789 -> neu chen tai i = 2 -> 012.3456789
    for (int i = startIndex; i < s.length(); i++) {
        // chi can i tai vi tri cuoi thi khong xet nua, vi khong the them dau . cuoi cung
        if (i == s.size() - 1) {
            if (total == 0 && checkValidIP(s, res)) {
                string temp = "";

                for (int k = 0; k < res.size(); ++k) {
                    temp += s[k];

                    if (res[k])
                        temp += ".";
                }

                if (dup.find(temp) == dup.end()) {
                    dup[temp] = true;
                    cout << temp << "\n";
                }
            }

            break;
        } else {
            if (total > 0) {
                // choose or not choose
                int prev = res[i];

                for (int j = 0; j <= 1; ++j) {
                    res[i] = j;
                    total -= j;

                    find(i + 1, total, s, res, dup);

                    total += j;
                    res[i] = prev;
                }
            } else {
                find(i + 1, total, s, res, dup);
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
    unordered_map<string, bool> dup;
    int total = 3;

    find(0, total, s, res, dup);
}