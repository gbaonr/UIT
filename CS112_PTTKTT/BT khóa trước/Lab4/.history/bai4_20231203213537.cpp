#include <bits/stdc++.h>
using namespace std;

void check(vector<bool>& res)
{
    long long t = 0;
}

// max length = 35
// it nhat 3 so => moi so toi da 12 chu so

void find(int startIndex, string s, int len, vector<bool>& res)
{
    if (len > 12) {
        return;
    }

    for (int i = startIndex; i < s.size(); ++i) {
        if (i == s.size() - 1) {

        } else {
            for (int j = 0; j <= 1; ++j) {
                if (j == 1) {

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