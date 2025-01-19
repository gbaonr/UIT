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

bool find(int cur, vector<char>& res, vector<int>& available)
{
    for (int i = 0; i < 2; i++) {
        if (available[i] > 0) {
            res[cur] = TEMP[i];
            available[i]--;

            if (cur == res.size() - 1) {
                if (check(res))
                    return true;
            } else {
                if (find(cur + 1, res, available))
                    return true;
            }
            available[i]++;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<char> res(2 * n);
    vector<int> available = { 0, 0 };
}