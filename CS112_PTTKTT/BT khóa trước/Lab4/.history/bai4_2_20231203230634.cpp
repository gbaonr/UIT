#include <bits/stdc++.h>
using namespace std;

bool find(int cur, long long sum, long long prev, long long prev2, int len, string& s)
{
    sum = sum * 10 + s[cur] - '0';

    if (cur == s.size() - 1) {
        
    }

    for (int i = 0; i <= 1; ++i) {
        if (i == 0) {
            // khong chen dau +
            if (prev != -1 && prev2 != -1) {
                if (sum > prev + prev2) {
                    return false;
                }
            }
        } else {
            if (prev != -1 && prev2 != -1) {
                if (sum > prev + prev2) {
                    return false;
                }
            }
        }
    }
}

int main()
{
}