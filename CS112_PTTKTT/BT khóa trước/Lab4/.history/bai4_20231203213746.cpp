#include <bits/stdc++.h>
using namespace std;

void check(vector<bool>& res)
{
    long long t = 0;
}

// max length = 35
// it nhat 3 so => moi so toi da 12 chu so

void check(vector<bool>& res, string& s) {
    for (int i = 0; i < res.size(); ++i) {
        cout << s[i];

        if (res[i] == 1) {
            cout << ".";
        }
    }
}

void find(int startIndex, string& s, int len, vector<bool>& res)
{
    if (len > 12) {
        return;
    }

    for (int i = startIndex; i < s.size(); ++i) {
        if (i == s.size() - 1) {

        } else {
            for (int j = 0; j <= 1; ++j) {
                if (j == 1) {
                    int prev = res[i];
                    res[i] = 1;

                    find(i + 1, s, 1, res);

                    res[i] = prev;
                } else {
                    // khong chen
                    find(i + 1, s, len + 1, res);
                }
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;
}