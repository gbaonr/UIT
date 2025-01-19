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
    map<char, int> c2i;
    map<int, char> i2c;
    vector<vector<bool>> G;
    int nV;

public:
    void nhap(int v, int e)
    {
        nV = v;
        G.assign(v, vector<bool>(v, 0));
        for (int i = 0; i < v; ++i) {
            char ch;
            cin >> ch;
            c2i[ch] = i;
            i2c[i] = ch;

            cout << ch << "-" << i << "\n";
        }

        for (int i = 0; i < e; ++i) {
            char a, b;
            cin >> a >> b;
            int ia = c2i[a];
            int ib = c2i[b];

            G[ia][ib] = 1;
            // G[ib][ia] = 1;
        }

        for (int i = 0; i < v; ++i) {
            for (int j = 0; j < v; ++j) {
                if (G[i][j]) {
                    cout << i << "-" << j << "\n";
                }
            }
        }

    }
    void myProcess(int n)
    {
        for (int i = 0; i < n; ++i) {
            int q;
            cin >> q;

            if (q == 1) {
                char u, v;
                cin >> u >> v;

                int iu = c2i[u];
                int iv = c2i[v];

                cout << (G[iu][iv] ? "TRUE" : "FALSE");
            } else if (q == 2) {
                char t;
                cin >> t;

                int it = c2i[t];
                bool found = false;

                for (int j = 0; j < nV; ++j) {
                    if (j != it && G[it][j]) {
                        cout << i2c[j] << " ";
                        found = true;
                    }
                }

                if (!found) {
                    cout << "NONE";
                }
            }

            cout << "\n";
        }
    }
};

int main()
{
    Graph G;
    int v, e, n;
    cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}
