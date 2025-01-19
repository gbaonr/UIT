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
    int vertex_num, e, n; // vertex num, edges num, so dinh can xet
    // vector<vector<int>> adj;
    map<string, vector<string>> adj;
    vector<int> colors; // store color of a vertex
    vector<string> vertices;
    unordered_map<string, int> mapping; // mapping name to index
    set<int> used_colors;
    vector<string> considers;

    void input()
    {
        cin >> this->vertex_num >> this->e >> this->n;
        string u, v;

        // nhap ten cac dinh trong do thi, tao mapping tu name -> idx
        for (int i = 0; i < this->vertex_num; i++)
        {
            cin >> u;
            vertices.push_back(u);
            mapping[u] = i;
        }

        // them canh
        for (int i = 0; i < e; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // khoi tao color
        int color;
        for (int i = 0; i < vertex_num; i++)
        {
            cin >> color;
            colors.push_back(color);
            // luu cac color da su dung
            if (color != -1)
            {
                used_colors.insert(color);
            }
        }

        // nhap vao cac dinh can xem xet
        for (int i = 0; i < n; i++)
        {
            cin >> u;
            considers.push_back(u);
        }
    }

    // ham thuc hien cong viec chinh
    void coloring()
    {
        // thuc hien tung yeu cau cho cac dinh can xem xet
        for (auto node : considers)
        {
            unordered_set<int> invalid_colors; // luu nhung color cua cac dinh ke
            // duyet qua cac dinh ke
            for (auto iter : adj[node])
            {
                if (colors[mapping[iter]] != -1)
                {
                    invalid_colors.insert(colors[mapping[iter]]);
                }
            }

            // neu dinh hien tai da duoc to mau
            if (colors[mapping[node]] != -1)
            {
                auto iter_find = invalid_colors.find(colors[mapping[node]]);
                if (iter_find != invalid_colors.end())
                {

                    // tim mau nho nhat co the su dung
                    int valid_color = -1;
                    // tim trong nhung mau da dung:
                    for (auto it : used_colors)
                    {
                        if (invalid_colors.find(it) == invalid_colors.end())
                        {
                            valid_color = it;
                            break;
                        }
                    }
                    // neu ko co color nao thoa thi tim mau moi
                    if (valid_color == -1)
                    {
                        for (int c = 0; c <= 16777215; c++)
                        {
                            if (invalid_colors.find(c) == invalid_colors.end())
                            {
                                valid_color = c;
                                break;
                            }
                        }
                    }
                    // colors[mapping[node]] = valid_color;
                    // if (valid_color != -1)
                    // {
                    //     used_colors.insert(valid_color);
                    // }
                    cout << valid_color << "\n";
                }
                else
                {
                    // neu ko trung mau => TRUE => next considered node
                    cout << "TRUE\n";
                    continue;
                }
            }
            // neu dinh hien tai chua duoc to mau
            else
            {
                // tim mau nho nhat co the su dung
                int valid_color = -1;
                // tim trong nhung mau da dung:
                for (auto it : used_colors)
                {
                    if (invalid_colors.find(it) == invalid_colors.end())
                    {
                        valid_color = it;
                        break;
                    }
                }
                // neu ko co color nao thoa thi tim mau moi
                if (valid_color == -1)
                {
                    for (int c = 0; c <= 16777215; c++)
                    {
                        if (invalid_colors.find(c) == invalid_colors.end())
                        {
                            valid_color = c;
                            break;
                        }
                    }
                }
                cout << valid_color << "\n";
            }
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