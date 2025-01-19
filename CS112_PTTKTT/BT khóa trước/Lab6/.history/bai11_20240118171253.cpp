#include <bits/stdc++.h>
using namespace std;

int n, W;
vector<int> w, p;

int dpFunc(int i, int total)
{
    if (i == n)
        return 0;

    return max(dpFunc(i + 1, total), dpFunc(i + 1, total + w[i]) + p[i]);
}

int main()
{
    cin >> n >> W;

    w.assign(n, 0);
    p.assign(n, 0);

    for (int i = 0; i < n; ++i)
        cin >> w[i] >> p[i];

    cout << dpFunc(0, 0);
}