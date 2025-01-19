#include <bits/stdc++.h>
using namespace std;

int n, W;
vector<int> w, p;
vector<vector<int>> dp;

int dpFunc(int i, int total)
{
    if (i == n)
        return 0;

    if (total + w[i] > W)
        return dpFunc(i + 1, total);

    return max(dpFunc(i + 1, total), dpFunc(i + 1, total + w[i]) + p[i]);
}

int main()
{
    cin >> n >> W;

    w.assign(n, 0);
    p.assign(n, 0);

    for (int i = 0; i < n; ++i)
        cin >> w[i] >> p[i];

    dp.assign(n + 1, vector<int>(accumulate(w.begin(), w.end(), 0), 0));

    for (int i = n - 1; i >= 0; --i) {

    }
}