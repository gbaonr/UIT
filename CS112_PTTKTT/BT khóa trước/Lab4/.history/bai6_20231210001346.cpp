#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    map<string, map<string, int>> m;
    for (int i = 0; i < n; i++) {
        string u, v;
        int w;

        cin >> u >> v >> w;

        m[u][v]++;
    }
}