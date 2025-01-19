#include <bits/stdc++.h>
using namespace std;

short n, m;

void update(short i, short j, short** t, short d)
{
    if (i - 1 >= 0)
        t[i - 1][j] += d;

    if (i + 1 < n)
        t[i + 1][j] += d;

    if (j - 1 >= 0)
        t[i][j - 1] += d;

    if (j + 1 < m)
        t[i][j + 1] += d;
}

void update2(short i, short j, short** t, short d)
{
    if (i - 1 >= 0)
        t[i - 1][j] = d;

    if (i + 1 < n)
        t[i + 1][j] = d;

    if (j - 1 >= 0)
        t[i][j - 1] = d;

    if (j + 1 < m)
        t[i][j + 1] = d;
}

bool checkConflict(short i, short j, short** num, short** matrix)
{
    return (i - 1 >= 0 && num[i - 1][j] > matrix[i - 1][j])
        || (i + 1 < n && num[i + 1][j] > matrix[i + 1][j])
        || (j - 1 >= 0 && num[i][j - 1] > matrix[i][j - 1])
        || (j + 1 < m && num[i][j + 1] > matrix[i][j + 1]);
}

void printArr(short** t)
{
    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; j++) {
            cout << t[i][j] << " \n"[j == m - 1];
        }
    }
}

void find(short index, short** matrix, short** res, short** num)
{
    if (index == n * m) {
        // printArr(num);
        // printArr(matrix);
        // cout << '\n';
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

    // != -1
    if (~res[row][col]) {
        find(index + 1, matrix, res, num);
        return;
    }

    // i = 0 -> khong co bom, i = 1 => co
    for (short i = 0; i <= 1; ++i) {
        if (i == 0) {
            res[row][col] = 0;

            if (row > 0 && (matrix[row - 1][col] - num[row - 1][col] > 0 || num[row - 1][col] > matrix[row - 1][col])) {
                continue;
            }

            if (col > 0 && (matrix[row][col - 1] - num[row][col - 1] > 1 || num[row][col - 1] > matrix[row][col - 1])) {
                continue;
            }

            if (col < m - 1 && (matrix[row][col + 1] - num[row][col + 1] > 2 || num[row][col + 1] > matrix[row][col + 1])) {
                continue;
            }

            if (row < n - 1 && (matrix[row + 1][col] - num[row + 1][col] > 3 || num[row + 1][col] > matrix[row + 1][col])) {
                continue;
            }

            find(index + 1, matrix, res, num);

            res[row][col] = -1;
        } else {
            update(row, col, num, 1);
            res[row][col] = 1;

            if (!checkConflict(row, col, num, matrix)) {
                find(index + 1, matrix, res, num);
            }

            res[row][col] = -1;
            update(row, col, num, -1);
        }
    }

    return;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    short** matrix = new short*[n];
    short** res = new short*[n];
    short** num = new short*[n];

    for (short i = 0; i < n; ++i) {
        matrix[i] = new short[m];
        res[i] = new short[m];
        num[i] = new short[m];
    }

    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    // update 0 first
    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                update2(i, j, res, 0);
            }
        }
    }

    printArr(res);
    find(0, matrix, res, num);
}
