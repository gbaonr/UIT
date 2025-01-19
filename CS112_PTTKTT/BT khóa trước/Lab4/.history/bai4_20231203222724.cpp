#include <bits/stdc++.h>
using namespace std;

void check(vector<bool>& res)
{
    long long t = 0;
}

// max length = 35
// it nhat 3 so => moi so toi da 12 chu so

int countDigit(long long n)
{
    if (n == 0)
        return 1;

    int count = 0;
    while (n) {
        n /= 10;
        ++count;
    }

    return count;
}

bool check(vector<bool>& res, string& s)
{
    for (int j = 0; j < res.size(); ++j) {
        cout << s[j];

        if (res[j] == 1) {
            cout << " + ";
        }
    }

    cout << '\n';

    long long sum = 0;
    long long a = -1, b = -1;
    int len = 0;
    int numDigit = 0;

    for (int i = 0; i < res.size(); ++i) {
        sum = sum * 10 + (s[i] - '0');
        len++;

        if (res[i] == 1) {
            numDigit++;

            if (countDigit(sum) != len)
                return false;

            if (a == -1) {
                a = sum;
            } else if (b == -1) {
                b = sum;
            } else {
                if (a + b != sum)
                    return false;

                a = b;
                b = sum;
            }

            len = 0;
            sum = 0;
        }
    }

    numDigit++;
    return numDigit >= 3 && a + b == sum;
}

void find(int startIndex, string& s, int len, long long prev1, long long prev2, long long cur, vector<bool>& res)
{
    cout << startIndex << ' ' << len << ' ' << prev1 << ' ' << prev2 << ' ' << cur << '\n';

    for (int i = startIndex; i < s.size(); ++i) {
        if (i == s.size() - 1) {
            if (check(res, s)) {
                // for (int j = 0; j < res.size(); ++j) {
                //     cout << s[j];

                //     if (res[j] == 1) {
                //         cout << " + ";
                //     }
                // }

                // cout << '\n';
                cout << "true";
                exit(0);
            }
        } else {
            // long long tcur = cur * 10 + (s[i] - '0');

            for (int j = 0; j <= 1; ++j) {
                if (j == 0 && len > 0) {
                    // chen dau +

                    int prev = res[i];
                    res[i] = 1;

                    find(i + 1, s, 0, prev2, cur, 0, res);

                    res[i] = prev;
                } else {
                    // khong chen dau +
                    long long tcur = cur * 10 + (s[i] - '0');

                    // truong hop neu co leading zero
                    if (len == 1 && cur == 0) {
                        cout << 'a';
                        break;
                    }

                    if (len + 1 > ceil(s.size() / 3.0)) {
                        return;
                    }

                    if (tcur > prev1 + prev2) {
                        return;
                    }

                    find(i + 1, s, len + 1, prev1, prev2, tcur, res);
                }
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;

    vector<bool> res(s.size(), 0);
    long long cur = s[0] - '0';

    find(0, s, 1, 1e15, 1e15, cur, res);

    cout << "false";
}