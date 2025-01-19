#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class Graph
{
public:
    int v, e;
    map<string, map<string, int>> adj;
    vector<string> vertices;
    map<string, int> index;
    vector<int> levels;

    void input()
    {
        string u, m;
        cin >> v >> e;
        levels = vector<int>(v, 0);

        for (int i = 0; i < v; i++)
        {
            cin >> u;
            vertices.push_back(u);
            index[u] = i;
        }

        for (int i = 0; i < e; i++)
        {
            cin >> u >> m;
            adj[u][m] = 1;
            adj[m][u] = 1;
            // tinh levels khi nhap
            levels[index[u]] += 1;
            levels[index[m]] += 1;
        }
    }
    void count_level()
    {
        for (auto it : levels)
        {
            cout << it << " ";
        }
    }
};

int main()
{
    Graph G;
    G.input();
    G.count_level();
    return 0;
}
