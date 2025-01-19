#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

class Graph
{
public:
    int vertex_num, e; // vertex num, edges num
    // vector<vector<int>> adj;
    map<string, vector<string>> adj;
    vector<int> colors; // store color of a vertex
    vector<string> vertices;
    unordered_map<string, int> mapping; // mapping name to index
    set<int> used_colors;

    void input()
    {
        cin >> this->vertex_num >> this->e;
        string u, v;

        // nhap ten cac dinh trong do thi, tao mapping tu name -> idx
        for (int i = 0; i < this->vertex_num; i++)
        {
            cin >> u;
            vertices.push_back(u);
            mapping[u] = i;
            colors.push_back(-1);
        }

        // them canh
        for (int i = 0; i < e; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void coloring()
    {
        // lap qua cac dinh trong do thi
        for (auto vertex : vertices)
        {
            // tim cac invalid_colors cho dinh hien tai
            set<int> invalid_colors;
            for (auto neighbor : adj[vertex])
            {
                if (colors[mapping[neighbor]] != -1)
                {
                    invalid_colors.insert(colors[mapping[neighbor]]);
                }
            }

            // tim valid color nho nhat
            int valid_color = -1;
            for (int c = 0; c < 16777215; c++)
            {
                if (invalid_colors.find(c) == invalid_colors.end())
                {
                    valid_color = c;
                    break;
                }
            }

            colors[mapping[vertex]] = valid_color;
            cout << valid_color << " ";
        }
    }
};

int main()
{
    Graph G;
    G.input();
    G.coloring();

    return 0;
}