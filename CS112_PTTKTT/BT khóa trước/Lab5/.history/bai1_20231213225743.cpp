#include <bits/stdc++.h>
using namespace std;

tuple<map<string, int>, map<string, string>, int> dijkstra(int n, map<string, map<string, int>>& g, string s, string d, vector<string>& vertices)
{
    // vector<int> res(n, INT_MAX);
    // vector<int> trace(n);
    map<string, int> res;
    map<string, string> trace;
    map<string, bool> closed;
    int totalOpened = 0;

    for (int i = 0; i < n; ++i) {
        res[vertices[i]] = INT_MAX;
        trace[vertices[i]] = "";
        closed[vertices[i]] = false;
    }

    // [dist, node]
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    res[s] = 0;
    pq.push({ 0, s });

    while (!pq.empty()) {
        string u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        totalOpened++;

        if (u == d)
            break;

        if (closed[u])
            continue;

        closed[u] = true;
        // neu node chuan bi xet < dist thuc te => nghia la node nay da duoc them vao pq voi dist nho hon
        // if (dist > res[u])
        //     continue;

        // for (auto edge : g[u]) {
        for (auto v : vertices) {
            int w = g[u][v];

            if (w == 0)
                continue;

            if (res[v] > dist + w) {
                res[v] = dist + w;
                trace[v] = u;
                pq.push({ res[v], v });
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

    // vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
    vector<string> vertices;
    map<string, map<string, int>> edges;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        vertices.push_back(s);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int w;
            cin >> w;
            edges[vertices[i]][vertices[j]] = w;
        }
    }

    reverse(vertices.begin(), vertices.end());

    for (int i = 0; i < q; ++i) {
        string u, v;
        cin >> u >> v;

        string t = v;

        auto ret = dijkstra(n, edges, u, v, vertices);
        auto dist = get<0>(ret);
        auto trace = get<1>(ret);
        auto totalOpened = get<2>(ret);

        if (dist[v] == INT_MAX) {
            cout << "no_path\n";
            cout << totalOpened << " 0" << endl;
            continue;
        }

        vector<string> path;
        while (v != u) {
            path.push_back(v);
            v = trace[v];
        }
        path.push_back(u);

        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << " ";
        }
        cout << endl;

        cout << totalOpened << " " << dist[t] << endl;
    }
}