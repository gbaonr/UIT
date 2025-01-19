#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s;
    cin >> s;

    long long res[max(s + 1, 7)] = { 0 };

    res[0] = 0;
    res[1] = 1;
    res[2] = res[1] + 1;
    res[3] = res[2] + 1;
    res[4] = res[3] + 1;
    res[5] = res[4] + 1;
    res[6] = res[5] + 1;

    cout << res[6];
}