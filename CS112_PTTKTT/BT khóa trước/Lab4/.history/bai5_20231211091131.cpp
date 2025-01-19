#include <bits/stdc++.h>
using namespace std;

short n, m;

void update(short i, short j, vector<vector<short>>& t, short d)
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

void update2(short i, short j, vector<vector<short>>& t, short d)
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

bool checkConflict(short i, short j, vector<vector<short>>& num, vector<vector<short>>& matrix)
{
    return (i - 1 >= 0 && num[i - 1][j] > matrix[i - 1][j])
        || (i + 1 < n && num[i + 1][j] > matrix[i + 1][j])
        || (j - 1 >= 0 && num[i][j - 1] > matrix[i][j - 1])
        || (j + 1 < m && num[i][j + 1] > matrix[i][j + 1]);
}

void printArr(vector<vector<short>>& t)
{
    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; j++) {
            cout << t[i][j] << " \n"[j == m - 1];
        }
    }
}

void find(short index, vector<vector<short>>& matrix, vector<vector<short>>& res, vector<vector<short>>& num)
{
    cout << index << '\n';
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
            if (row > 0 && (matrix[row - 1][col] - num[row - 1][col] > 0 || num[row - 1][col] > matrix[row - 1][col])) {
                cout << "1\n";
                continue;
            }

            if (col > 0 && (matrix[row][col - 1] - num[row][col - 1] > (1 - (row == n - 1)) || num[row][col - 1] > matrix[row][col - 1])) {
                cout << "2\n";
                continue;
            }

            if (col < m - 1 && (matrix[row][col + 1] - num[row][col + 1] > (2 - (row == n - 1) - (col == m - 2)) || num[row][col + 1] > matrix[row][col + 1])) {
                cout << "3\n";
                continue;
            }

            if (row < n - 1 && (matrix[row + 1][col] - num[row + 1][col] > (3 - (row == n - 2) - (col == m - 1) - (col == 0)) || num[row + 1][col] > matrix[row + 1][col])) {
                continue;
            }

            res[row][col] = 0;
            find(index + 1, matrix, res, num);
            res[row][col] = -1;
        } else {
            if (row > 0 && (num[row - 1][col] + 1 > matrix[row - 1][col] || (num[row - 1][col] + 1 < matrix[row - 1][col])))
                continue;

            if (col > 0 && (num[row][col - 1] + 1 > matrix[row][col - 1] || (num[row][col - 1] + 2 < matrix[row][col - 1])))
                continue;

            if (col < m - 1 && (num[row][col + 1] + 1 > matrix[row][col + 1] || (num[row][col + 1] + 3 < matrix[row][col + 1])))
                continue;

            if (row < n - 1 && (num[row + 1][col] + 1 > matrix[row + 1][col] || (num[row + 1][col] + 4 < matrix[row + 1][col])))
                continue;

            update(row, col, num, 1);
            res[row][col] = 1;

            find(index + 1, matrix, res, num);

            res[row][col] = -1;
            update(row, col, num, -1);
        }
    }

    return;
}

int main()
{
    cin >> n >> m;

    vector<vector<short>> matrix(n, vector<short>(m));
    vector<vector<short>> res(n, vector<short>(m, -1));
    vector<vector<short>> num(n, vector<short>(m));

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

    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; j++) {
            if (matrix[i][j] == 4) {
                if (i > 0 && res[i - 1][j] == -1) {
                    res[i - 1][j] = 1;
                    update(i - 1, j, num, 1);
                }

                if (i < n - 1 && res[i + 1][j] == -1) {
                    res[i + 1][j] = 1;
                    update(i + 1, j, num, 1);
                }

                if (j > 0 && res[i][j - 1] == -1) {
                    res[i][j - 1] = 1;
                    update(i, j - 1, num, 1);
                }

                if (j < m - 1 && res[i][j + 1] == -1) {
                    res[i][j + 1] = 1;
                    update(i, j + 1, num, 1);
                }

                if (i > 0 && res[i - 1][j] ==)
                    update(i - 1, j, num, 1);

                if (i < n - 1)
                    update(i + 1, j, num, 1);

                if (j > 0)
                    update(i, j - 1, num, 1);

                if (j < m - 1)
                    update(i, j + 1, num, 1);

                printArr(num);
            }
        }
    }

    printArr(res);
    cout << '\n';
    printArr(num);

    find(0, matrix, res, num);
}