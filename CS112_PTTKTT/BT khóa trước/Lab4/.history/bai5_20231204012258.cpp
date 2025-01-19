#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> matrix, res, num;

char n, m;

void update(char i, char j, vector<vector<char>>& t, char d, bool inc = true)
{
    if (i - 1 >= 0) {
        if (inc)
            t[i - 1][j] += d;
        else
            t[i - 1][j] = d;
    }

    if (i + 1 < n) {
        if (inc)
            t[i + 1][j] += d;
        else
            t[i + 1][j] = d;
    }

    if (j - 1 >= 0) {
        if (inc)
            t[i][j - 1] += d;
        else
            t[i][j - 1] = d;
    }

    if (j + 1 < m) {
        if (inc)
            t[i][j + 1] += d;
        else
            t[i][j + 1] = d;
    }
}

bool checkConflict(char i, char j)
{
    if (i - 1 >= 0)
        if (num[i - 1][j] > matrix[i - 1][j])
            return true;

    if (i + 1 < n)
        if (num[i + 1][j] > matrix[i + 1][j])
            return true;

    if (j - 1 >= 0)
        if (num[i][j - 1] > matrix[i][j - 1])
            return true;

    if (j + 1 < m)
        if (num[i][j + 1] > matrix[i][j + 1])
            return true;

    return false;
}

void printArr(vector<vector<char>>& t)
{
    for (char i = 0; i < n; ++i) {
        for (char j = 0; j < m; j++) {
            cout << (int) t[i][j] << " \n"[j == m - 1];
        }
    }
}

void find(short index)
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
            update(row, col, num, 1, true);
            res[row][col] = 1;

            if (!checkConflict(row, col)) {
                find(index + 1);
            }

            res[row][col] = -1;
            update(row, col, num, -1, true);
        }
    }

    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    matrix.assign(n, vector<char>(m));
    res.assign(n, vector<char>(m, -1));
    num.assign(n, vector<char>(m));

    for (char i = 0; i < n; ++i) {
        for (char j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    // update 0 first
    for (char i = 0; i < n; ++i) {
        for (char j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                update(i, j, res, 0, false);
            }
        }
    }

    printArr(res);
    // printArr(num);

    find(0);
}