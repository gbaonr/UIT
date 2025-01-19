/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <vector>
using namespace std;

// ###INSERT CODE HERE -
void inputGraph(vector<vector<int>>& G, int v, int e)
{
    G.assign(v, vector<int>(v, 0));
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        G[--u][--v] = 1;
    }
}

void process(vector<vector<int>>& G, int v, int n)
{
    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;

        if (q == 1) {
            int u, v;
            cin >> u >> v;
            cout << (G[--u][--v] ? "TRUE" : "FALSE");
        } else if (q == 2) {
            int t;
            cin >> t;
            bool found = false;
            --t;
            for (int j = 0; j < v; ++j) {
                if (j != t && G[t][j]) {
                    cout << j + 1 << " ";
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

int main()
{

    int v, e, n;
    cin >> v >> e >> n; // v: số đỉnh, e: số cạnh, n: số thao tác
    vector<vector<int>> G;

    inputGraph(G, v, e);
    process(G, v, n);

    return 0;
}
