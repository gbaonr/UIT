#include <bits/stdc++.h>

using namespace std;

struct compare {
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.first > b.first;
    }
};

int astar(int n, int m, pair<int, int> start, pair<int, int> end, vector<vector<int>> a)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
    vector<vector<int>> close(m, vector<int>(n, 0));
    vector<vector<int>> open(m, vector<int>(n, 0));
    vector<vector<int>> g(m, vector<int>(n));
    vector<vector<int>> f(m, vector<int>(n));
    vector<vector<pair<int, int>>> parent(m, vector<pair<int, int>>(n));

    vector<int> dx = { 0, 0, 1, -1 };
    vector<int> dy = { 1, -1, 0, 0 };
    g[start.first][start.second] = 0;
    pq.push({ 0, start });
    bool flag = false;
    while (!pq.empty()) {
        pair<int, pair<int, int>> u = pq.top();
        pq.pop();
        close[u.second.first][u.second.second] = 1;
        if (u.second == end) {
            flag = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int loopCount = 0;
            if (dx[i] == 0) {
                if (dy[i] == 1) {
                    loopCount = n - u.second.second;
                } else {
                    loopCount = u.second.second + 1;
                }
            } else {
                if (dx[i] == 1) {
                    loopCount = m - u.second.first;
                } else {
                    loopCount = u.second.first + 1;
                }
            }
            for (int j = 1; j < loopCount; j++) {
                int x = u.second.first + j * dx[i];
                int y = u.second.second + j * dy[i];
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    break;
                }
                if (a[x][y] == 1) {
                    break;
                }
                int w = 0;
                if (a[x][y] == 0) {
                    w = 1;
                }
                if (w == 0)
                    continue;
                if (!close[x][y]) {
                    if (open[x][y] && g[u.second.first][u.second.second] + w >= g[x][y]) {
                        continue;
                    }

                    g[x][y] = g[u.second.first][u.second.second] + w;
                    f[x][y] = g[x][y];
                    parent[x][y] = { u.second.first, u.second.second };
                    pq.push({ f[x][y], { x, y } });
                    open[x][y] = 1;
                }
                if (close[x][y] == 1 && g[u.second.first][u.second.second] + w < g[x][y]) {
                    g[x][y] = g[u.second.first][u.second.second] + w;
                    f[x][y] = g[x][y];
                    parent[x][y] = { u.second.first, u.second.second };
                    pq.push({ f[x][y], { x, y } });
                    open[x][y] = 1;
                    close[x][y] = 0;
                }
            }
        }
    }

    if (flag) {
        int total = 0;
        pair<int, int> temp = { end.first, end.second };
        pair<int, int> prev_move = { 0, 0 };
        while (temp.first != start.first || temp.second != start.second) {
            pair<int, int> move = { temp.first - parent[temp.first][temp.second].first, temp.second - parent[temp.first][temp.second].second };
            if (move.first != prev_move.first || move.second != prev_move.second) {
                total++;
            }
            prev_move = move;
            temp = parent[temp.first][temp.second];
        }
        return total;
    } else {
        return -1;
    }
}

int main()
{
    int m, n;
    pair<int, int> start, end;
    cin >> m >> n;
    cin >> start.first >> start.second;
    cin >> end.first >> end.second;
    vector<vector<int>> a(m, vector<int>(n, 0));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    // printMatrix(a);
    cout << astar(n, m, start, end, a);
}