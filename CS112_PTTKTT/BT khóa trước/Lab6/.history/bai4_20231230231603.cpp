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
    res[3] = res[1] + res[2] + 1;
    res[4] = res[3] + 1;
    res[5] = res[4] + 1;
    res[6] = res[5] + 1;

    for (int i = 7; i <= s; i++) {
        res[i] = res[i - 1] + res[i - 2] + res[i - 3] + res[i - 4] + res[i - 5] + res[i - 6];
    }

    cout << res[s];
}