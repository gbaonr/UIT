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

int countBoom(int i, int j)
{
    int count = 0;

    for (auto v : { -1, 1 }) {
        if (i + v >= 0 && i + v < n)
            count += res[i + v][j];

        if (j + v >= 0 && j + v < m)
            count += res[i][j + v];
    }

    return count;
}

bool checkConflict(int i, int j)
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

void printArr(vector<vector<int>>& t)
{
    cout << "arr:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            cout << t[i][j] << " \n"[j == m - 1];
        }
    }
}

void find(int index)
{
    if (index == n * m) {
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         if (countBoom(i, j) != matrix[i][j])
        //             return;
        //     }
        // }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << res[i][j] << " \n"[j == m - 1];
            }
        }

        exit(0);
    }

    int row = index / m;
    int col = index % m;

    if (res[row][col] != -1) {
        find(index + 1);
        return;
    }

    // i = 0 -> khong co bom, i = 1 => co
    bool temp = false;

    for (int i = 0; i <= 1; ++i) {
        if (i == 0) {
            res[row][col] = 0;

            if (row > 0) {
                if (num[row - 1][col] != matrix[row - 1][col]) {
#ifdef DEBUG
                    cout << "conflict " << row << ' ' << col << '\n';
                    cout << "num:"
                         << "\n";
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                            cout << num[i][j] << " \n"[j == m - 1];
                        }
                    }
                    cout << "matrix:"
                         << "\n";
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                            cout << matrix[i][j] << " \n"[j == m - 1];
                        }
                    }
#endif
                    return;
                }
            }

            find(index + 1);

            res[row][col] = -1;
        } else {
            update(row, col, num, 1);
            res[row][col] = 1;

            if (!checkConflict(row, col)) {
                find(index + 1);
            }

            res[row][col] = -1;
            update(row, col, num, -1);
        }
    }

    return;
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

    // update 0 first
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                update(i, j, res, 0, false);
            }
        }
    }

    find(0);
}