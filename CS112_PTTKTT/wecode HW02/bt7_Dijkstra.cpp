#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
class Graph
{
public:
    vector<vector<int>> matrix;            // ma tran ke
    vector<string> names;                  // ten cac dinh
    map<string, int> indexs;               // map de luu index cac dinh
    int v;                                 //// so luong dinh trong do thi
    int e;                                 // so canh trong do thi
    vector<pair<string, string>> requests; // luu cac cap canh bat dau va ket thuc

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

        int w;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cin >> w;
                matrix[i][j] = w;
            }
        }

        string v1, v2;
        for (int i = 0; i < e; i++)
        {
            cin >> v1 >> v2;
            requests.push_back(make_pair(v1, v2));
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

    string find_min_d(set<string> open, map<string, int> d)
    {
        string res = *open.begin();
        int min_d = d[res];
        for (auto node : open)
        {
            if (d[node] <= min_d)
            {
                min_d = d[node];
                res = node;
            }
        }
        return res;
    }

    void dijkstra()
    {
        // xu ly tung request
        for (auto req : requests)
        {
            // khoi tao
            string start = req.first;
            string end = req.second;
            vector<string> path;
            map<string, string> parents;
            bool found = false;
            int opened_nodes = 0;
            int total_weight = 0;
            set<string> open;
            set<string> close;
            map<string, int> d;

            open.insert(start);
            d[start] = 0;

            // chay thuat toan
            while (open.size() > 0)
            {
                // B2.1: Chon p thuoc open co d nho nhat
                string p = find_min_d(open, d);

                // B2.2: neu p la end -> ket thuc
                if (p == end)
                {
                    found = true;
                    break;
                }

                // B2.3: neu p da duyet roi thi skip
                if (close.find(p) != close.end())
                {
                    continue;
                }

                // B2.4: move p to close, open p's neighbor
                close.insert(p);
                open.erase(p);

                for (int i = 0; i < v; i++)
                {
                    // kiem tra dinh co phai neighbor cua p khong
                    if (matrix[indexs[p]][i] != 0)
                    {
                        d[names[i]] = d[p] + matrix[indexs[p]][i];
                        open.insert(names[i]);
                        parents[names[i]] = p;
                    }
                }

                // them dinh vao opened_node
                opened_nodes += 1;
            }

            if (found == true)
            {
                string node = end;
                do
                {
                    path.push_back(node);
                    node = parents[node];
                } while (node != start);
                for (auto it = path.end(); it != path.begin(); it--)
                {
                    cout << *it << " ";
                }
                cout << "\n";
                cout << opened_nodes << " " << d[end];
            }
        }
    }
};

int main()
{
    Graph G;
    G.createGraph();
    G.show();
    G.dijkstra();
    // vector<string> test = G.dinh_ke("AA");
    // cout << "\n";
    // for (auto iter:test){
    //     cout << iter << "(" << G.indexs[iter] << ")" << " ";
    // }
    // cout << endl;
}
