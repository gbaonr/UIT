#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix, res;

void find(int num)
{
}

int main()
{
    int n, m;
    cin >> n >> m;

    matrix.assign(n, vector<int>(m, 0));
    res.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
}