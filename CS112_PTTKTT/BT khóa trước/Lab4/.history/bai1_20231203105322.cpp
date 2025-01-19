#include <bits/stdc++.h>
using namespace std;

char TEMP[2] = { '(', ')' };

bool check(vector<char>& res)
{
    int n = res.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (res[i] == '(')
            cnt++;
        else
            cnt--;
        if (cnt < 0)
            return false;
    }
    return cnt == 0;
}

void find(int cur, vector<char>& res, vector<int>& available)
{
    for (int i = 0; i < 2; i++) {
        if (available[i] > 0) {
            res[cur] = TEMP[i];
            available[i]--;

            if (cur == res.size() - 1) {
                if (check(res)) {
                    for (int i = 0; i < res.size(); i++)
                        cout << res[i];

                    cout << "\n"
                }
            } else {
                find(cur + 1, res, available);
            }

            available[i]++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<char> res(2 * n);
    vector<int> available = { 0, 0 };

    find(0, res, available);
}