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
    map<string, int> c2i;
    map<int, string> i2c;
    vector<vector<bool>> G;
    int nV;

public:
    void nhap(int e)
    {
        for (int i = 0; i < e; ++i) {
            string a, b;
            cin >> a >> b;

            if (c2i.find(a) != c2i.end()) {
                c2i[a] = c2i.size();
                i2c[i2c.size() - 1] = a;
            }

            if (c2i.find(b) != c2i.end()) {
                c2i[b] = c2i.size();
                i2c[i2c.size() - 1] = b;
            }

            G[c2i[a]][c2i[b]] = 1;
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

                int iu = c2i[u];
                int iv = c2i[v];

                cout << (G[iu][iv] ? "TRUE" : "FALSE");
            } else if (q == 2) {
                string t;
                cin >> t;

                int it = c2i[t];
                int countAdj = 0;

                for (int j = 0; j < nV; ++j)
                    countAdj += j != it && G[it][j];
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
    G.myProcess(n);
    return 0;
}
