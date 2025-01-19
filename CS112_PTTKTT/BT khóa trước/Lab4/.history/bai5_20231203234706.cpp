#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix, res, num;

int n, m;

void update(int i, int j, vector<vector<int>>& t, int d, bool inc = true)
{
    if (i > 0)
        if (inc)
            t[i - 1][j] += d;
        else
            t[i - 1][j] = d;

    if (i < n - 1)
        if (inc)
            t[i + 1][j] += d;
        else
            t[i + 1][j] = d;

    if (j > 0)
        if (inc)
            t[i][j - 1] += d;
        else
            t[i][j - 1] = d;

    if (j < m - 1)
        if (inc)
            t[i][j + 1] += d;
        else
            t[i][j + 1] = d;
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
    num.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
}