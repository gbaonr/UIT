#include <iostream>
#include <vector>
#include <map>
#include <string>
#include<set>
using namespace std;



class myGraph
{
public:
    map<string, map<string, int>> G;
    set<string> vortex; // mang de luu danh sach cac ten dinh

    void input(long int e, long int n)
    {
        for (int i = 0; i < e; i++){
            string u, v;
            vortex.insert(u);
            vortex.insert(v);
            int w;
            cin >> u >> v;
            cin >> w;
            G[u][v] = w;
        }
    }

    void process(int n)
    {
        for (int a = 0; a < n; a++)
        {
            //nhap vao duong di
            vector<string> v_list;
            string inp;
            while(1){
                cin >> inp;
                if (inp != ".")
                    v_list.push_back(inp);
                else
                    break;
            }

           
            if (v_list.front() != v_list.back())
            {
                cout << "FALSE" << endl;
                continue;
            }
            
            int dis = 0;
            int flag = 1;

            for (int i = 0; i < v_list.size()-1; i++ ){
                string u = v_list[i];
                string v = v_list[i+1];

                if (G.find(u) != G.end())
                {
                    map<string, int> s = G[u];
                    if (s.find(v) != s.end())
                        dis += s[v];
                    else 
                    {
                        flag = 0;
                        break;
                    }
                }
                else 
                {
                    flag = 0;
                    break;
                }
            }
            
            if (flag == 0)
                cout << "FALSE" << endl;
            else
                cout << dis << endl;
        }
    }

    bool check(string u, string v){
        if (G.find(u) != G.end())
        {
            map<string, int> s = G[u];
            if (s.find(v) != s.end())
                return true;
        }

        return false;
    }

    void _myProcess(int n)
    {
        map<string, map<string,int>> adj_list = G;
        for (int i = 0; i < n; i++)
        {
            vector<string> path;
            string x;
            while (1)
            {
                cin >> x;
                if (x != ".")
                    path.push_back(x);
                else
                    break;
            }
            if (path.front() == path.back())
            {
                int length = 0;
                int flag = 1;
                for (int j = 0; j < path.size() - 1; j++)
                {
                    string d1 = path[j];
                    string d2 = path[j + 1];
                    if (adj_list.find(d1) != adj_list.end())
                    {
                        map<string, int> s = adj_list[d1];
                        if (s.find(d2) != s.end())
                            length += s[d2];
                        else
                        {
                            flag = 0;
                            break;
                        }
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag != 0)
                    cout << length << endl;
                else
                    cout << "FALSE" << endl;
            }
            else
                cout << "FALSE" << endl;
        }
    }

};

int main()
{
    myGraph G;
    long e, n;
    cin >> e >> n;
    G.input(e, n);
    G.process(n);

    return 0;
}