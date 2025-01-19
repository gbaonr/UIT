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
    map<string, map<string, int>> G;

public:
    void nhap(int e)
    {
        for (int i = 0; i < e; ++i) {
            string a, b;
            int w;
            cin >> a >> b >> w;

            if (G.find(a) == G.end()) {
                G[a] = map<string, int>();
            }

            G[a][b] = w;
        }
    }

    void myProcess(int n)
    {
        for (int i = 0; i < n; ++i) {
            string prev;
            cin >> prev;
            int w = -1;

            if (prev != ".") {
                while (1) {
                    string cur;
                    cin >> cur;

                    if (cur == ".")
                        break;

                    if ((prev != cur) && (G.find(prev) == G.end() || G[prev].find(cur) == G[prev].end())) {
                        cout << "Fix: " << prev << " - " << cur << "\n";
                        w = -1;
                        break;
                    }

                    cout << prev << "->" << cur << " = " << G[prev][cur] << "\n";
                    w += G[prev][cur];
                    prev = cur;
                    cout << "a";
                }
            }

            cout << w << "\n";
            if (w == -1) {
                cout << "FALSE";
            } else {
                cout << w;
            }

            cout << "\n\n\n";
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
