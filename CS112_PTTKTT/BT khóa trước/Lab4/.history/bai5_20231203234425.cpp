#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix, res, num;

int n, m;

void update(int i, int j, int d)
{
    if (i > 0)
        num[i - 1][j] += d;

    if (i < n - 1)
        res[i + 1][j] += d;

    if (j > 0)
        res[i][j - 1] += d;

    if (j < m - 1)
        res[i][j + 1] += d;
}

void find(int i, int j)
{
    if (matrix[i][j] == 0) {
    }
}

int main()
{
    cin >> n >> m;

    matrix.assign(n, vector<int>(m, 0));
    res.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
}