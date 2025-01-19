#include <bits/stdc++.h>
using namespace std;

void check(vector<bool> res) {

}

void find(int startIndex, string s, vector<bool>& res)
{
    for (int i = startIndex; i < s.size(); ++i) {
        if (i == s.size() - 1) {

        } else {
            for (int j = 0; j <= 1; ++j) {
                int prev = res[i];
                res[i] = j;

                find(i + 1, s, res);

                res[i] = prev;
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;
}