#include <bits/stdc++.h>

using namespace std;

void Astar(int v, int e, string start, string end, vector<string> vertex, vector<int> cost, vector<vector<int>> edge, map<string, int> vertexCost, map<string, int> vertexMap)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> open;
    vector<bool> close(v, 0);
    vector<int> g(v, INT_MAX);
    vector<int> f(v, -1);
    map<string, string> parent;
    g[vertexMap[start]] = 0;
    open.push(make_pair(0, vertexMap[start]));
    vector<int> openSet;
    int vertexCount = 0;
    openSet.push_back(vertexMap[start]);
    bool flag = false;
    while (!open.empty()) {
        int u = open.top().second;
        open.pop();
        close[u] = true;
        if (vertex[u] == end) {
            flag = true;
            break;
        }
        for (int i = 0; i < v; i++) {
            if (close[i] == false && edge[u][i] != 0 && find(openSet.begin(), openSet.end(), i) == openSet.end()) {
                //         TH1:  q không thuộc Open và q không thuộc Close
                //             g(q)  =  g(p) + cost(p,q);
                //             f(q)   =  g(q) + h(q);    // h(q)  là giá trị heuristic
                //             prev(q) = p
                //             Thêm q vào Open
                g[i] = g[u] + edge[u][i];
                f[i] = g[i] + vertexCost[vertex[i]];
                parent[vertex[i]] = vertex[u];
                open.push(make_pair(f[i], i));
                openSet.push_back(i);
            }
            if (close[i] == false && edge[u][i] != 0 && find(openSet.begin(), openSet.end(), i) != openSet.end()) {
                //         TH2: q thuộc Open
                //             if(g(q) > g(p) + cost(p,q)) // nếu đến được q bằng path ngắn hơn    thì cập nhật lại q trong Open
                //                 g(q) = g(p) + cost(p,q);
                //                 f(q)  = g(q) + h(q );
                //                 prev(q) = p
                if (g[i] > g[u] + edge[u][i]) {
                    g[i] = g[u] + edge[u][i];
                    f[i] = g[i] + vertexCost[vertex[i]];
                    parent[vertex[i]] = vertex[u];
                    open.push(make_pair(f[i], i));
                    openSet.push_back(i);
                }
            }
            if (close[i] == true && edge[u][i] != 0) {
                //         TH3: q thuộc Close
                //             if(g(q) > g(p) + cost(p,q)) // nếu đến được q bằng path ngắn hơn
                //                 Bỏ q khỏi Close
                //                 g(q) = g(p) + cost(p,q);
                //                 f(q)  = g(q) + h(q );
                //                 prev(q) = p
                //                 Thêm q vào Open
                //                 Cập nhật các đỉnh chịu ảnh hưởng từ sự thay đổi của q
                if (g[i] > g[u] + edge[u][i]) {
                    close[i] = false;
                    g[i] = g[u] + edge[u][i];
                    f[i] = g[i] + vertexCost[vertex[i]];
                    parent[vertex[i]] = vertex[u];
                    open.push(make_pair(f[i], i));
                    openSet.push_back(i);
                    for (int j = 0; j < v; j++) {
                        if (!close[j] && edge[i][j] != 0 && find(openSet.begin(), openSet.end(), j) == openSet.end()) {
                            g[j] = g[i] + edge[i][j];
                            f[j] = g[j] + vertexCost[vertex[j]];
                            parent[vertex[j]] = vertex[i];
                            open.push(make_pair(f[j], j));
                            openSet.push_back(j);
                        }
                    }
                }
            }
        }
    }
    if (!flag) {
        cout << "-unreachable-" << endl;
        for (int i = 0; i < v; i++) {
            if (close[i]) {
                vertexCount++;
            }
        }
        cout << vertexCount << " " << 0 << endl;
    } else {
        vector<string> path;
        string current = end;
        int totalCost = 0;
        while (current != start) {
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
        for (string s : path) {
            cout << s << " ";
        }
        for (int i = 0; i < path.size() - 1; i++) {
            totalCost += edge[vertexMap[path[i]]][vertexMap[path[i + 1]]];
        }
        // for (string s : path) {
        //     totalCost += vertexCost[s];
        // }
        for (int i = 0; i < v; i++) {
            if (close[i]) {
                vertexCount++;
            }
        }
        cout << endl
             << vertexCount << " " << totalCost << endl;
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    string start, end;
    vector<string> vertex(v);
    vector<int> cost(v);
    vector<vector<int>> edge(v, vector<int>(v));
    map<string, int> vertexCost;
    map<string, int> vertexMap;
    cin >> start >> end;
    for (int i = 0; i < v; i++) {
        cin >> vertex[i];
        vertexMap[vertex[i]] = i;
    }
    for (int i = 0; i < v; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < e; i++) {
        string u, v;
        int c;
        cin >> u >> v >> c;
        edge[vertexMap[u]][vertexMap[v]] = c;
    }
    for (int i = 0; i < v; i++) {
        vertexCost[vertex[i]] = cost[i];
    }
    Astar(v, e, start, end, vertex, cost, edge, vertexCost, vertexMap);
}