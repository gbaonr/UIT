#include <iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<set>

using namespace std;
class Graph{
public:
    vector<vector<int>> matrix; // ma tran ke 
    vector<string> names;   // ten cac dinh
    map<string,int> indexs; // map de luu index cac dinh
    map<string, int> h; // map de luu heuristic value cua cac dinh
    int v; //// so luong dinh trong do thi 
    int e; // so canh trong do thi
    string start, end; // diem bat dau va ket thuc cho thuat toan astar

    void createGraph(){
        cin >> v >> e;
        cin >> start >> end;
        string vertex;
        for (int i = 0; i < v; i++){
            cin >> vertex;
            names.push_back(vertex);
            indexs[vertex] = i;
            matrix.push_back(vector<int>(v, 0));
        }
        int heuristic;
        for (int i = 0; i < v; i++){
            cin >> heuristic;
            h[names[i]] = heuristic;
        }
        string e1, e2;
        int fx;
        for (int i = 0; i < e; i++){
            cin >> e1 >> e2 >> fx;
            matrix[indexs[e1]][indexs[e2]] = fx;
        }
    }

    void show(){
        for (int i = 0; i < v; i++){
            for (auto iter:matrix[i]){
                cout << iter << " ";
            }
            cout << "\n";
        }
    }

    vector<string> dinh_ke(string p){
        vector<string> res;
        for (int i = 0; i < matrix[indexs[p]].size(); i++){
            if (matrix[indexs[p]][i] != 0)
            res.push_back(names[i]);
        }
        return res;
    }

    vector<string> Astar(){
        // priority_queue<pair<int, int>>  open; // pair.first = vertex index, pair.second = g(p)

        set<string> open;
        set<string> close;
        map<string, string> parent;
        map<string, int> g;
        map<string, int> f;
        bool found = false;

        //B0: input 

        // B1:
        open.insert(start);
        g[start] = 0;
        f[start] = h[start];
        

        //B2: 
        while(!open.empty()){
            //Chon p thuoc Open co f nho nhat
            int anchor = 99999;
            set<string>::iterator p_i, pmin;
            p_i = open.begin();
            pmin = open.begin();
            for (p_i = open.begin(); p_i != open.end(); p_i++){
                if (f[*p_i] < f[*pmin] || (f[*p_i] == f[*pmin] && indexs[*p_i] < indexs[*pmin])){
                    pmin = p_i;
                }
            }
            

            //B2.2: 
            string p = *pmin;
            if (p == end){ // neu p = dich
                close.insert(p);
                found = true;
                break;
            }

            //Buoc 2.3: duyet xong dinh p, them p vao close
            close.insert(p);
            open.erase(p);

            //Buoc 2.4:  xet cac dinh ke q cua p
            vector<string> adj = this->dinh_ke(p);
            for (int i = 0; i < adj.size(); i++) //xet qua tung dinh ke
            {
                string q = adj[i];
                //Kiem tra xem q da co trong close hay open chua

                set<string>::iterator cit = close.find(q);
                if (cit == close.end()){
                    set<string>::iterator oit = open.find(q);
                    if (oit == open.end())                  // TH1: q ko co trong open and close , tich hop TH2 vao luon vi giong code
                    {
                        //g[p] da co san
                        g[q] = g[p] + matrix[indexs[p]][indexs[q]];
                        // them mot mang parent de luu parent
                        f[q] = g[q] + h[q];
                        parent[q] = p;
                        open.insert(q);
                    }
                    else                                    // TH2: q co trong open
                    {
                        if (g[q] > g[p] + matrix[indexs[p]][indexs[q]]){ // neu den duoc q bang duong ngan hon -> update q
                            //g[p] da co san
                            g[q] = g[p] + matrix[indexs[p]][indexs[q]];
                            // them mot mang parent de luu parent
                            f[q] = g[q] + h[q];
                            parent[q] = p;
                        }
                    }
                }
                else                                        // TH3: q thuoc close
                {
                    if (g[q] > g[p] + matrix[indexs[p]][indexs[q]]){ // neu den duoc q bang duong ngan hon -> update q
                        //bo q khoi close
                        close.erase(q);
                        g[q] = g[p] + matrix[indexs[p]][indexs[q]];
                        f[q] = g[q] + h[q];
                        parent[q] = p;
                        open.insert(q);

                    }
                }

            }


        }

        int numExploredNodes = close.size();
        vector<string> path;
        if (found){
            path.push_back(end);
            string node = end;
            do {
                path.insert(path.begin(), parent[node]);
                node = parent[node];
            } while (node != start);
            int cost = 0;
            for (int i = 0; i < path.size() - 1; i++){
                cost += matrix[indexs[path[i]]][indexs[path[i+1]]];
            }

            for (auto iter:path){
                cout << iter << " ";
            }
            
            cout << "\n";
            cout << numExploredNodes << " " << cost << "\n";
        }
        else // khong tim duoc duong di 
        {
            cout << "-unreachable-\n";
            cout << numExploredNodes << " " << "0\n";
        }
        return path;
    }

};

int main(){
    Graph G;
    G.createGraph();
    // G.show();
    // vector<string> test = G.dinh_ke("AA");
    // cout << "\n";
    // for (auto iter:test){
    //     cout << iter << "(" << G.indexs[iter] << ")" << " ";
    // }
    // cout << endl;
    G.Astar();

}
