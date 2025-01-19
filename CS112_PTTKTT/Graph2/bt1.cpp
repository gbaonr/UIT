#include <iostream>
#include <vector>
#include <map>
#include <string>
#include<set>
using namespace std;



class myGraph
{
public:
    map<string,set<string>> G;


    void input(long int e, long int n)
    {
        for (int i = 0; i < e; i++){
            string u, v;
            cin >> u >> v;
            G[v]; //Tao anh xa tu v --> {} tap rong
            G[u].insert(v); //Tao anh xa tu u --> {} tap rong. roi them v vao tap do

        }
    }

    string isAdj(string x, string y)
    {
        set<string> s = G[x];
        if ( s.find(y) != s.end())
            return "TRUE";
        return "FALSE";
    }

    void process(long n)
    {
        int req;
        for (int i = 0; i < n; i++)
        {
            cin >> req;

            if (req == 1)
            {
                string u, v;
                cin >> u >> v;
                cout <<isAdj(u,v) << endl;
            }

            if (req == 2) 
            {
                string u;
                cin >> u;
                cout << (G[u].size()) << endl;
            }

        }
    }



};

int main()
{
    myGraph G;
    long e, n;
    cin >> e >> n;
    G.input(e, n);
    G.process(n);

    return 0;
}