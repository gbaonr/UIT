#include <iostream>
#include <vector>
using namespace std;

short n, m;
// vector<vector<short>> matrix;
// vector<vector<short>> res;
// vector<vector<short>> num;
short matrix[40][40];
short res[40][40];
short num[40][40];

// void update(short i, short j, short* t, short d)
void update(short i, short j, short t[40][40], short d)
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

void update2(short i, short j, short t[40][40], short d)
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

bool checkConflict(short i, short j)
{
    return (i - 1 >= 0 && num[i - 1][j] > matrix[i - 1][j])
        || (i + 1 < n && num[i + 1][j] > matrix[i + 1][j])
        || (j - 1 >= 0 && num[i][j - 1] > matrix[i][j - 1])
        || (j + 1 < m && num[i][j + 1] > matrix[i][j + 1]);
}

void printArr(short t[40][40], string dem = ' ')
{
    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; j++) {
            cout << t[i][j] << (dem + "\n")[j == m - 1];
        }
    }
}

void find(short index)
{
    if (index == n * m) {
        // if (num != matrix)
        //     return;
        for (short i = 0; i < n; ++i) {
            for (short j = 0; j < m; ++j) {
                if (num[i][j] != matrix[i][j])
                    return;
            }
        }

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
        find(index + 1);
        return;
    }

    // i = 0 -> khong co bom, i = 1 => co
    for (short i = 0; i <= 1; ++i) {
        if (i == 0) {
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

            res[row][col] = 0;
            find(index + 1);
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

            find(index + 1);

            res[row][col] = -1;
            update(row, col, num, -1);
        }
    }

    return;
}

int main()
{
    cin >> n >> m;

    // vector<vector<short>> matrix(n, vector<short>(m));
    // vector<vector<short>> res(n, vector<short>(m, -1));
    // vector<vector<short>> num(n, vector<short>(m));
    // matrix.resize(n, vector<short>(m));
    // res.resize(n, vector<short>(m, -1));
    // num.resize(n, vector<short>(m));

    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            res[i][j] = -1;
            num[i][j] = 0;
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

    auto func = [&](short i, short j) {
        if (i - 1 >= 0 && res[i - 1][j] == -1) {
            res[i - 1][j] = 1;
            update(i - 1, j, num, 1);
        }

        if (i + 1 < n && res[i + 1][j] == -1) {
            res[i + 1][j] = 1;
            update(i + 1, j, num, 1);
        }

        if (j - 1 >= 0 && res[i][j - 1] == -1) {
            res[i][j - 1] = 1;
            update(i, j - 1, num, 1);
        }

        if (j + 1 < m && res[i][j + 1] == -1) {
            res[i][j + 1] = 1;
            update(i, j + 1, num, 1);
        }
    };

    // update 4
    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; j++) {
            if (matrix[i][j] == 4) {
                func(i, j);
            }
        }
    }

    // update 3
    for (short i = 0; i < n; ++i) {
        // 0th col
        if (matrix[i][0] == 3) {
            func(i, 0);
        }

        // (m - 1)th col
        if (matrix[i][m - 1] == 3) {
            func(i, m - 1);
        }
    }

    for (short i = 0; i < m; ++i) {
        // 0th row
        if (matrix[0][i] == 3) {
            func(0, i);
        }

        // (n - 1)th row
        if (matrix[n - 1][i] == 3) {
            func(n - 1, i);
        }
    }

    // update 2
    if (m > 1 && n > 1) {
        if (matrix[0][0] == 2) {
            func(0, 0);
        }

        if (matrix[0][m - 1] == 2) {
            func(0, m - 1);
        }

        if (matrix[n - 1][0] == 2) {
            func(n - 1, 0);
        }

        if (matrix[n - 1][m - 1] == 2) {
            func(n - 1, m - 1);
        }
    }

    // pre calculate
    for (int t = 0; t < 2; ++t) {
        for (short i = 0; i < n; ++i) {
            for (short j = 0; j < m; j++) {
                short totalBoom = 0, totalMiss = 0;

                if (i - 1 >= 0) {
                    totalBoom += res[i - 1][j] == 1;
                    totalMiss += res[i - 1][j] == -1;
                }

                if (i + 1 < n) {
                    totalBoom += res[i + 1][j] == 1;
                    totalMiss += res[i + 1][j] == -1;
                }

                if (j - 1 >= 0) {
                    totalBoom += res[i][j - 1] == 1;
                    totalMiss += res[i][j - 1] == -1;
                }

                if (j + 1 < m) {
                    totalBoom += res[i][j + 1] == 1;
                    totalMiss += res[i][j + 1] == -1;
                }

                if (totalMiss > 0 && totalBoom + totalMiss == matrix[i][j]) {
#ifdef DEBUG
                    cout << "update " << i << ' ' << j << '\n';
#endif
                    func(i, j);
                }
            }
        }
    }

#ifdef DEBUG
    printArr(res, ',');
#endif
    find(0);
}