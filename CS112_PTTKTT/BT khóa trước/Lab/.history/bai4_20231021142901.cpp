/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

// ###INSERT CODE HERE -
class Graph {
private:
    map<string, int> countAdj;
    map<string, vector<string>> G;
    int nV;

public:
    void nhap(int e)
    {
        nV = e;
        for (int i = 0; i < e; ++i) {
            string a, b;
            cin >> a >> b;

            if (G.find(a) == G.end()) {
                G[a] = vector<string>();
            }

            if (G.find(b) == G.end()) {
                G[b] = vector<string>();
            }

            G[a].push_back(b);
        }
    }

    void myProcess(int n)
    {
        for (int i = 0; i < n; ++i) {
            int q;
            cin >> q;

            if (q == 1) {
                string u, v;
                cin >> u >> v;

                if (find(G[u].begin(), G[u].end(), v)) {

                }
            } else if (q == 2) {
                string t;
                cin >> t;

                int it = c2i[t];
                cout << countAdj[it];
            }

            cout << "\n";
        }
    }
};

int main()
{
    Graph G;
    int e, n;
    cin >> e >> n;
    G.nhap(e);
    // G.myProcess(n);
    return 0;
}
