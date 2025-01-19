#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(m, vector<int>(n));
    for (auto& v : a)
        for (auto& x : v)
            cin >> x;

    for (int i = 0; i < n; i++) {
        int minValue = a[0][i];
        int minIndex = 0;

        for (int j = 1; j < m; j++) {
            if (a[j][i] < minValue) {
                minValue = a[j][i];
                minIndex = j;
            }
        }

        cout << minIndex << " ";
    }
}