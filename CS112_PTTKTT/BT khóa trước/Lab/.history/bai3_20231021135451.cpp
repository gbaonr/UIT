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

public:
    void nhap(int v, int e)
    {
        for (int i = 0; i < v; ++i) {
            char ch;
            cin >> ch;
            c2i[ch] = i;
            i2c[i] = ch;
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
