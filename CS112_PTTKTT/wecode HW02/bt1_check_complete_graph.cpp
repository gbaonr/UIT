#include<iostream>
#include<set>
#include<unordered_map>

using namespace std;

class Graph{
public:
    int e;
    unordered_map<string, set<string>> adj;
    set<string> names;
    void input(){
        cin >> e;
        string v1, v2;
        for (int i = 0; i < e; i++){
            cin >> v1 >> v2;
            adj[v1].insert(v2);
            names.insert(v1);
            names.insert(v2);
        }
    }
    void isComplete(){
        set<string>::iterator v1, v2;
        for (v1 = names.begin(); v1 != names.end(); v1++){
            set<string> adjv1 = adj[*v1];
            for (v2 = adjv1.begin(); v2 != adjv1.end(); v2++){
                if (adj[*v2].find(*v1) == adj[*v2].end()){
                    cout << "FALSE\n";
                    return;
                }
            }
        }
        cout << "TRUE\n";
        return;
    }
};

int main(){
    Graph G;
    G.input();
    G.isComplete();
    return 0;
}