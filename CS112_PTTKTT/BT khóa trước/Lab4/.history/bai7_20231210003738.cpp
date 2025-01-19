#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(m, vector<int>(n));
    for (auto& v : a) {
        for (auto& x : v) {
            cin >> x;
        }
    }
}