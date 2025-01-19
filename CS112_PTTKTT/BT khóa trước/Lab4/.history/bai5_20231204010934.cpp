#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> matrix, res, num;

char n, m;

void update(char i, char j, vector<vector<char>>& t, char d, bool inc = true, bool checkRes = true)
{
    for (auto v : { -1, 1 }) {
        if (i + v >= 0 && i + v < n) {
            if ((checkRes && res[i + v][j] == -1) || !checkRes) {
                if (inc)
                    t[i + v][j] += d;
                else
                    t[i + v][j] = d;
            }
        }

        if (j + v >= 0 && j + v < m) {
            if ((checkRes && res[i][j + v] == -1) || !checkRes) {
                if (inc)
                    t[i][j + v] += d;
                else
                    t[i][j + v] = d;
            }
        }
    }
}

char countBoom(char i, char j)
{
    char count = 0;

    for (auto v : { -1, 1 }) {
        if (i + v >= 0 && i + v < n)
            count += res[i + v][j];

        if (j + v >= 0 && j + v < m)
            count += res[i][j + v];
    }

    return count;
}

bool checkConflict(char i, char j)
{
    for (auto v : { -1, 1 }) {
        if (i + v >= 0 && i + v < n)
            if (num[i + v][j] > matrix[i + v][j])
                return true;

        if (j + v >= 0 && j + v < m)
            if (num[i][j + v] > matrix[i][j + v])
                return true;
    }

    return false;
}

void prcharArr(vector<vector<char>>& t)
{
    for (char i = 0; i < n; ++i) {
        for (char j = 0; j < m; j++) {
            cout << t[i][j] << " \n"[j == m - 1];
        }
    }
}

void find(char index)
{
    if (index == n * m) {
        if (num != matrix)
            return;

        for (char i = 0; i < n; ++i) {
            for (char j = 0; j < m; ++j) {
                cout << res[i][j] << " \n"[j == m - 1];
            }
        }

        exit(0);
    }

    char row = index / m;
    char col = index % m;

    if (res[row][col] != -1) {
        find(index + 1);
        return;
    }

    // i = 0 -> khong co bom, i = 1 => co
    bool temp = false;

    for (char i = 0; i <= 1; ++i) {
        if (i == 0) {
            res[row][col] = 0;

            if (row > 0) {
                if (num[row - 1][col] != matrix[row - 1][col]) {
                    continue;
                }
            }

            find(index + 1);

            res[row][col] = -1;
        } else {
            update(row, col, num, 1, true, false);
            res[row][col] = 1;

            if (!checkConflict(row, col)) {
                find(index + 1);
            }

            res[row][col] = -1;
            update(row, col, num, -1, true, false);
        }
    }

    return;
}

int main()
{
    cin >> n >> m;

    matrix.assign(n, vector<char>(m, 0));
    res.assign(n, vector<char>(m, -1));
    num.assign(n, vector<char>(m, 0));

    for (char i = 0; i < n; ++i) {
        for (char j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    // update 0 first
    for (char i = 0; i < n; ++i) {
        for (char j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                update(i, j, res, 0, false, false);
            }
        }
    }

    // prcharArr(res);
    // prcharArr(num);

    find(0);
}