#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> start, end, p;

void dpFunc(int i)
{
}

int main()
{
    cin >> n;

    start.resize(n);
    end.resize(n);
    p.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> start[i] >> end[i] >> p[i];
}