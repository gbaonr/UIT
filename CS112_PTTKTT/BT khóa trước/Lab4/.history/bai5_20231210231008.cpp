#include <iostream>
#include <vector>

using namespace std;

void update(short i, short j, vector<vector<short>>& t, short d, short n, short m)
{
    t[i - 1][j] += d;
    t[i + 1][j] += d;
    t[i][j - 1] += d;
    t[i][j + 1] += d;
}

void update2(short i, short j, vector<vector<short>>& t, short d, short n, short m)
{
    t[i - 1][j] = d;
    t[i + 1][j] = d;
    t[i][j - 1] = d;
    t[i][j + 1] = d;
}

bool checkConflict(short i, short j, vector<vector<short>>& num, vector<vector<short>>& matrix, short n, short m)
{
    return (i > 0 && num[i - 1][j] > matrix[i - 1][j])
        || (i < n - 1 && num[i + 1][j] > matrix[i + 1][j])
        || (j > 0 && num[i][j - 1] > matrix[i][j - 1])
        || (j < m - 1 && num[i][j + 1] > matrix[i][j + 1]);
}

void printArr(vector<vector<short>>& t)
{
    for (auto& row : t) {
        for (auto& elem : row) {
            cout << elem << ' ';
        }
        cout << '\n';
    }
}

void find(short index, vector<vector<short>>& matrix, vector<vector<short>>& res, vector<vector<short>>& num, short n, short m)
{
    cout << index << '\n';

    if (index == n * m) {
        for (short i = 1; i <= n; ++i) {
            for (short j = 1; j <= m; ++j) {
                if (num[i][j] != matrix[i][j]) {
                    return;
                }
            }
        }

        printArr(res);
        exit(0);
    }

    short row = index / m + 1;
    short col = index % m + 1;

    // != -1
    if (~res[row][col]) {
        find(index + 1, matrix, res, num, n, m);
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

            find(index + 1, matrix, res, num, n, m);

            res[row][col] = -1;
        } else {
            update(row, col, num, 1, n, m);
            res[row][col] = 1;

            if (!checkConflict(row, col, num, matrix, n, m)) {
                find(index + 1, matrix, res, num, n, m);
            }

            res[row][col] = -1;
            update(row, col, num, -1, n, m);
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    short n, m;
    cin >> n >> m;

    vector<vector<short>> matrix(n + 2, vector<short>(m + 2));
    vector<vector<short>> res(n + 2, vector<short>(m + 2, -1));
    vector<vector<short>> num(n + 2, vector<short>(m + 2));

    for (short i = 1; i <= n; ++i) {
        for (short j = 1; j <= m; ++j) {
            cin >> matrix[i][j];
        }
    }

    printArr(matrix);

    // update 0 first
    for (short i = 1; i <= n; ++i) {
        for (short j = 1; j <= m; j++) {
            if (matrix[i][j] == 0) {
                update2(i, j, res, 0, n, m);
            }
        }
    }

    printArr(res);
    find(0, matrix, res, num, n, m);
}