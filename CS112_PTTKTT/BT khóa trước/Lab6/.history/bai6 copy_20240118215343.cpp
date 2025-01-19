#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<int, int, int>> a, b, p;

void dpFunc(int i)
{
}

int main()
{
    cin >> n;

    a.resize(n);
    b.resize(n);
    p.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> p[i];
}