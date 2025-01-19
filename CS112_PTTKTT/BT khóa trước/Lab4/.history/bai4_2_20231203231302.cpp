#include <bits/stdc++.h>
using namespace std;

// em khong thay co cam su dung backtracking loai nay
// em thay cai nay de hon, nen e implement

bool find(int cur, long long sum, long long prev, long long prev2, int len, string& s)
{
    auto tsum = sum * 10 + s[cur] - '0';
    auto tlen = len + 1;

    if (cur == s.size() - 1) {
        // chua du 3 so
        if (prev == -1 || prev2 == -1) {
            return false;
        }

        return tsum == prev + prev2;
    }

    bool res = false;

    for (int i = 0; i <= 1; ++i) {
        if (i == 0) {
            // khong chen dau +

            // leading zeros
            if (tlen > 1 && sum == 0) {
                return false;
            }

            if (prev != -1 && prev2 != -1) {
                // khong them dau + nhung ket qua hien tai da lon hon tong 2 so truoc do => khong can xet nua
                if (tsum > prev + prev2) {
                    return false;
                }
            }

            res |= find(cur + 1, tsum, prev, prev2, tlen, s);
        } else {
            if (prev != -1 && prev2 != -1) {
                // them dau + nhung ket qua hien tai khac tong 2 so truoc do => khong can xet nua
                if (tsum != prev + prev2) {
                    return false;
                }
            }

            res |= find(cur + 1, 0, prev2, tsum, 0, s);
        }
    }

    return res;
}

int main()
{
    string s;
    cin >> s;

    cout << (find(0, 0, -1, -1, 0, s) ? "true" : "false");
}