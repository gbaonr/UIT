#include <bits/stdc++.h>
using namespace std;

bool checkValidIP(string s, vector<bool> res)
{
}

void find(int startIndex, int& total, string s, vector<bool>& res)
{
    for (int i = startIndex; i < s.size() - 1; i++) {
        if (i == s.size() - 2) {

        } else {}
        if (total > 0) {
            // choose or not choose
            for (int j = 0; j <= 1; ++j) {
                res[i] = j;
                total -= j;

                if (i == s.size() - 2) {
                    if (total == 0 && checkValidIP(s, res)) {
                        for (int k = 0; k < res.size(); ++k) {
                            cout << s[k];

                            if (res[k])
                                cout << ".";
                        }
                    }
                } else {
                    find(i + 1, total, s, res);
                }

                total += j;
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;
}