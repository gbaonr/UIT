#include <bits/stdc++.h>
using namespace std;

pair<vector<int>, vector<int>> dijkstra(int n, vector<vector<pair<int, int>>> g, int s, int d)
{
    vector<int> res(n, INT_MAX);
    vector<int> trace(n);

    // [dist, node]
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    res[s] = 0;
    pq.push({ 0, s });

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (u)

        // neu node chuan bi xet < dist thuc te => nghia la node nay da duoc them vao pq voi dist nho hon
        if (dist > res[u])
            continue;

        // for (auto edge : g[u]) {
        for (int v = n - 1; v >= 0; --v) {
            int w = g[u][v];

            if (w == 0)
                continue;

            if (res[v] > dist + w) {
                res[v] = dist + w;
                pq.push({ res[v], v });
                trace[v] = u;
            }
        }
    }

    return {
        res,
        trace
    };
}

int main()
{
    int n, q;
    cin >> n >> q;

    map<string, int> label2id;
    map<int, string> id2label;

    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());

    for (int i = 0; i < n; ++i) {
        string c;
        cin >> c;

        label2id[c] = i;
        id2label[i] = c;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int w;
            cin >> w;

            g[i].push_back({ j, w });
        }
    }

    for (int i = 0; i < q; ++i) {
        string _u, _v;
        cin >> _u >> _v;

        int u = label2id[_u];
        int v = label2id[_v];
        int t = v;

        auto ret = dijkstra(n, g, u);
        auto dist = ret.first;
        auto trace = ret.second;

        if (dist[v] == INT_MAX) {
            cout << "-unreachable-\n";
            continue;
        }

        vector<int> path;
        while (v != u) {
            path.push_back(v);
            v = trace[v];
        }
        path.push_back(u);

        for (int i = path.size() - 1; i >= 0; --i) {
            cout << id2label[path[i]] << " ";
        }
        cout << endl;

        cout << dist[t] << endl;
    }
}