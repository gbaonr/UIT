/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<iostream>
using namespace std;

void inputGraph(bool*[], int);
void process(bool*[], int, int);



int main()
{
	int v, e, n; //v: số đỉnh, e: số cạnh, n: số thao tác
	cin >> v >> e >> n;

	bool **G; // ma trận toàn số 0, 1 nên kiểu bool hay int đều được


//###INSERT CODE HERE -
    G = new bool*[v];
    for (int i = 0; i < v; ++i) {
        G[i] = new bool[v] {0};
        // for (int j = 0; j < v; ++j)
        //     G[i][j] = 0;
    }

    for (int i = 0; i < e; ++i) {
        int u, v; cin >> u >> v;
        G[--u][--v] = 1;
    }

    for (int i = 0; i < n; ++i) {
        int q; cin >> q;
        if (q == 1) {
            int u, v; cin >> u >> v;
            cout << (G[--u][--v] ? "TRUE" : "FALSE");
        } else if (q == 2) {
            int t; cin >> t;
            for (int j = 0; j < v; ++j) {
                if (i != t && G[t][j]) {
                    cout << j + 1 << " ";
                }
            }
        }

        cout << "\n";
    }
}
