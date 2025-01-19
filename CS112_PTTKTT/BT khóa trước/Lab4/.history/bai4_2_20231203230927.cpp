#include <bits/stdc++.h>
using namespace std;

bool find(int cur, long long sum, long long prev, long long prev2, int len, string& s)
{
    auto tsum = sum * 10 + s[cur] - '0';
    len++;

    if (cur == s.size() - 1) {
        if (prev == -1 || prev2 == -1) {
            return false;
        }
    }

    for (int i = 0; i <= 1; ++i) {
        if (i == 0) {
            // khong chen dau +

            // leading zeros
            if (len > 1 && sum == 0) {
                return false;
            }

            if (prev != -1 && prev2 != -1) {
                // khong them dau + nhung ket qua hien tai da lon hon tong 2 so truoc do => khong can xet nua
                if (tsum > prev + prev2) {
                    return false;
                }
            }
        } else {
            if (prev != -1 && prev2 != -1) {
                // them dau + nhung ket qua hien tai khac tong 2 so truoc do => khong can xet nua
                if (tsum != prev + prev2) {
                    return false;
                }
            }
        }
    }
}

int main()
{
}