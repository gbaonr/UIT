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

public:
    void nhap(int v, int e)
    {
        G.assign(v, vector<int> (v, 0));
        for (int i = 0; i < v; ++i) {
            char ch;
            cin >> ch;
            c2i[ch] = i;
            i2c[i] = ch;
        }

        for (int i = 0; i < e; ++i) {
            char a, b; cin >> a >> b;
            int ia = c2i[a];
            int ib = c2i[b];

            
        }
    }
    void myProcess(int n)
    {
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
