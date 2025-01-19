#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class Graph
{
public:
    vector<vector<int>> matrix;            // Ma trận kề
    vector<string> names;                  // Tên các đỉnh
    map<string, int> indexs;               // Map để lưu chỉ số các đỉnh
    int v;                                 // Số lượng đỉnh trong đồ thị
    int e;                                 // Số cạnh trong đồ thị
    vector<pair<string, string>> requests; // Lưu các cặp cạnh bắt đầu và kết thúc

    void createGraph()
    {
        cin >> v >> e;
        string vertex;
        for (int i = 0; i < v; i++)
        {
            cin >> vertex;
            names.push_back(vertex);
            indexs[vertex] = i;
            matrix.push_back(vector<int>(v, 0));
        }

        string v1, v2;
        for (int i = 0; i < e; i++)
        {
            cin >> v1 >> v2;
            int u = indexs[v1], v = indexs[v2];
            matrix[u][v] = matrix[v][u] = 1; // Vì là đồ thị vô hướng
        }
    }

    void show()
    {
        for (int i = 0; i < v; i++)
        {
            for (auto iter : matrix[i])
            {
                cout << iter << " ";
            }
            cout << "\n";
        }

        for (auto p : requests)
        {
            cout << p.first << " " << p.second << "\n";
        }
    }

    string find_min_d(priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> &pq, map<string, int> &d)
    {
        while (!pq.empty())
        {
            string node = pq.top().second;
            pq.pop();
            return node;
        }
        return "";
    }

    void dijkstra()
    {
        for (auto req : requests)
        {
            string start = req.first;
            string end = req.second;
            vector<string> path;
            map<string, string> parents;
            bool found = false;
            int opened_nodes = 0;

            priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
            set<string> closed_set;
            map<string, int> d;

            for (const auto &name : names)
            {
                d[name] = INT_MAX;
            }
            d[start] = 0;
            pq.push({0, start});

            while (!pq.empty())
            {
                string p = find_min_d(pq, d);
                if (p == end)
                {
                    opened_nodes += 1;
                    found = true;
                    break;
                }

                if (closed_set.find(p) != closed_set.end())
                {
                    continue;
                }

                closed_set.insert(p);

                int p_index = indexs[p];
                for (int i = 0; i < v; i++)
                {
                    if (matrix[p_index][i] != 0)
                    {
                        string q = names[i];
                        if (closed_set.find(q) == closed_set.end())
                        {
                            int new_dist = d[p] + matrix[p_index][i];
                            if (new_dist < d[q])
                            {
                                d[q] = new_dist;
                                parents[q] = p;
                                pq.push({new_dist, q});
                            }
                        }
                    }
                }
                opened_nodes++;
            }

            if (found)
            {
                string node = end;
                path.push_back(node);
                while (node != start)
                {
                    node = parents[node];
                    path.push_back(node);
                }
                reverse(path.begin(), path.end());

                for (const auto &node : path)
                {
                    cout << node << " ";
                }
                cout << "\n";
                cout << opened_nodes << " " << d[end] << "\n";
            }
            else
            {
                cout << "-unreachable-\n";
                cout << opened_nodes << " " << 0 << "\n";
            }
        }
    }
};

int main()
{
    Graph G;
    G.createGraph();
    G.dijkstra();
    return 0;
}
