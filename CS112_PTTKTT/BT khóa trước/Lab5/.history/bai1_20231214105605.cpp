#include <bits/stdc++.h>
using namespace std;

tuple<vector<int>, vector<int>, int> dijkstra(int n, vector<vector<int>> g, int s, int d)
{
    vector<int> res(n, INT_MAX);
    vector<int> trace(n);
    int totalOpened = 0;

    // [dist, node]
    auto customSort = [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
            return a.second > b.second;

        return a.first < b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(customSort)> pq;

    res[s] = 0;
    pq.push({ 0, s });

    while (!pq.empty()) {
        // print all node in pq
        cout << "\n-----\n";
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(customSort)> pq2 = pq;
        while (!pq2.empty()) {
            cout << pq2.top().second << " " << pq2.top().first << endl;
            pq2.pop();
        }

        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        totalOpened++;

        if (u == d) {
            break;
        }

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
        trace,
        totalOpened
    };
}

int main()
{
    int n, q;
    cin >> n >> q;

    map<string, int> label2id;
    map<int, string> id2label;

    vector<vector<int>> g(n, vector<int>());

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

            g[i].push_back(w);
        }
    }

    for (int i = 0; i < q; ++i) {
        string _u, _v;
        cin >> _u >> _v;

        int u = label2id[_u];
        int v = label2id[_v];
        int t = v;

        auto ret = dijkstra(n, g, u, v);
        auto dist = get<0>(ret);
        auto trace = get<1>(ret);
        auto totalOpened = get<2>(ret);

        if (dist[v] == INT_MAX) {
            cout << "-unreachable-\n";
            cout << totalOpened << " 0" << endl;
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

        cout << totalOpened << " " << dist[t] << endl;
        cout << "====\n\n";
    }
}