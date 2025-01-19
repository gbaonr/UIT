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
    set<string> names;
    map<string, int> mark;
    vector<string> path;
    vector<string> res_path;
    int totalW = 999999;
    int tempW = 0;

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

    void backtracking(int k)
    {
        if (k <= names.size()){
            string node = path.back();
            for (const auto& [it, value]:adj[node])
            {
                if (mark[it] == 1 || (path.size() < names.size() && it == start))
                {
                    continue;
                }
                path.push_back(it);
                mark[it] = 1;
                tempW += adj[node][it];
                
                if (it == start){
                    if (tempW <= totalW)
                    {
                        totalW = tempW;
                        res_path = path;
                    }
                }
                else
                {
                    this->backtracking(k+1);
                }
                tempW -= adj[node][it];
                mark[it] = 0;
                path.pop_back();
            }
        }

    }
    void find_path()
    {
        backtracking(0);
        for (auto it:res_path){
            cout << it << " ";
        }
    }
    
};

int main()
{
    Graph G;
    G.Input();
    G.find_path();
}