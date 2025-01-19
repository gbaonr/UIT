#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Graph
{
public:
    int e, w;
    string v1, v2;
    string start;
    map<string, map<string, int>> adj;
    vector<string> path;
    set<string> names;
    map<string, int> mark;

    void Input()
    {
        cin >> e;
        cin >> start;
        path.push_back(start);
        for (int i = 0; i < e; i++)
        {
            cin >> v1 >> v2 >> w;
            adj[v1][v2] = w;
            mark[v1] = 0;
            names.insert(v1);
            names.insert(v2);
        }
    }

    void find_path()
    {
        while (path.size() <= names.size())
        {
            string node = path.back();
            string node_min_child;
            int minW = 9999999;
            for (const auto &[it, value] : adj[node])
            {
                if (mark[it] == 1 || (path.size() < names.size() && it == start))
                {
                    continue;
                }
                if (value <= minW)
                {
                    minW = value;
                    node_min_child = it;
                }
            }
            path.push_back(node_min_child);
            mark[node_min_child] = 1;
        }
        for (int i = 0; i < path.size()-1; i++){
            cout << path[i] << " ";
        }
        cout << "\n" << path.back();
    }
};

int main()
{
    Graph G;
    G.Input();
    G.find_path();
}