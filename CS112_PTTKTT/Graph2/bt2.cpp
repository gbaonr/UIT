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

    // bool isAdj(map<string x, string y)
    // {
    //     set<string> s = G[x];
    //     if ( s.find(y) != s.end())
    //         return true;
    //     return false;
    // }
    void ii(vector<string> h){
        for (int i = 0; i<h.size(); i++){
            cout << h[i]; 
        }
        cout << " jsalkdjalksdj";
    }
    vector<string> inputArray(){
        vector<string> v_list;
        string inp;
        while(1)
        {
            cin >> inp;
            if (inp == "."){
                // ii(v_list);
                return v_list;
            }
            else{
                v_list.push_back(inp);
            }
        }
    }

    void process(long n)
    {
        for (int a = 0; a < n; a++)
        {
            vector<string> v_list = inputArray();
            //truong hop khi mang nhap vao khong co dinh nao
            if (v_list.size() == 0) 
            {
                cout << "FALSE" << endl;
                break;
            }
            if (v_list.front() != v_list.back())
            {
                cout << "FALSE" << endl;
                break;
            }
            
            int dis = 0;


            for (int i = 0; i < v_list.size()-1; i++ ){
                string u = v_list[i];
                string v = v_list[i+1];
                if (u == v){
                    dis += 0;
                    continue;
                }
                if (check(u, v)){
                    dis += G[u][v];
                    // cout << " add " << G[u][v] << endl;
                }
                else {
                    dis = -1;
                    break;
                }
            }
            
            if (dis == -1)
                cout << "FALSE" << endl;
            else
                // cout << "dis = " << dis << endl;
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