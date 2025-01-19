#include <bits/stdc++.h>
using namespace std;

void find(int startIndex, int& total, string s, vector<bool>& res) {
    for (int i = startIndex; i < s.size() - 1; i++) {
        if (total > 0) {
            // choose or not choose
            for (int j = 0; j <= 1; ++j) {
                res[i] = j;
                total -= j;

                if (i == s.size() - 2) {
                    if (total == 0) {

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