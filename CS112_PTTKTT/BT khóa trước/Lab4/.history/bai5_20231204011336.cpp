#include <bits/stdc++.h>
using namespace std;

vector<vector<short>> matrix, res, num;

short n, m;

void update(short i, short j, vector<vector<short>>& t, short d, bool inc = true, bool checkRes = true)
{
    if (i - 1 >= 0) {
        if ((checkRes && res[i - 1][j] == -1) || !checkRes) {
            if (inc)
                t[i - 1][j] += d;
            else
                t[i - 1][j] = d;
        }
    }

    if (i + 1 < n) {
        if ((checkRes && res[i + 1][j] == -1) || !checkRes) {
            if (inc)
                t[i + 1][j] += d;
            else
                t[i + 1][j] = d;
        }
    }

    if (j - 1 >= 0) {
        if ((checkRes && res[i][j - 1] == -1) || !checkRes) {
            if (inc)
                t[i][j - 1] += d;
            else
                t[i][j - 1] = d;
        }
    }

    if (j + 1 < m) {
        if ((checkRes && res[i][j + 1] == -1) || !checkRes) {
            if (inc)
                t[i][j + 1] += d;
            else
                t[i][j + 1] = d;
        }
    }
}

short countBoom(short i, short j)
{
    short count = 0;

    for (auto v : { -1, 1 }) {
        if (i + v >= 0 && i + v < n)
            count += res[i + v][j];

        if (j + v >= 0 && j + v < m)
            count += res[i][j + v];
    }

    return count;
}

bool checkConflict(short i, short j)
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

void prshortArr(vector<vector<short>>& t)
{
    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; j++) {
            cout << t[i][j] << " \n"[j == m - 1];
        }
    }
}

void find(short index)
{
    if (index == n * m) {
        if (num != matrix)
            return;

        for (short i = 0; i < n; ++i) {
            for (short j = 0; j < m; ++j) {
                cout << res[i][j] << " \n"[j == m - 1];
            }
        }

        exit(0);
    }

    short row = index / m;
    short col = index % m;

    if (res[row][col] != -1) {
        find(index + 1);
        return;
    }

    // i = 0 -> khong co bom, i = 1 => co
    bool temp = false;

    for (short i = 0; i <= 1; ++i) {
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

    matrix.assign(n, vector<short>(m, 0));
    res.assign(n, vector<short>(m, -1));
    num.assign(n, vector<short>(m, 0));

    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    // update 0 first
    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                update(i, j, res, 0, false, false);
            }
        }
    }

    // prshortArr(res);
    // prshortArr(num);

    find(0);
}