#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix, res, num;

int n, m;

void update(int i, int j, vector<vector<int>>& t, int d, bool inc = true)
{
    for (auto v : { -1, 1 }) {
        if (i + v >= 0 && i + v < n) {
            if (inc)
                t[i + v][j] += d;
            else
                t[i + v][j] = d;
        }

        if (j + v >= 0 && j + v < m) {
            if (inc)
                t[i][j + v] += d;
            else
                t[i][j + v] = d;
        }
    }
}

void find(int index)
{
    int row = index / m;
    int col = index % m;

    if (matrix[row][col] == 0) {
        update(row, col, res, 0, false);
        find(index + 1);
        return;
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