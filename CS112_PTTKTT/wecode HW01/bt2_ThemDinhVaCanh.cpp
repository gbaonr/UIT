#include <iostream>

#include <string>
#include <unordered_map>
using namespace std;

class Graph
{
public:
    // vector<vector<int>> adjList;
    unordered_map<string, int> mapping;
    string u, v;

    unordered_map<string, unordered_map<string, bool>> adjList;

    bool checkVertex(const string &v) // neu dinh co trong map -> true, else -> false
    {
        if (adjList.find(v) != adjList.end())
            return true;
        return false;
    }

    bool checkEdge(string u, string v) // neu uv co trong adjList[u] -> true, else -> false
    {
        if (adjList[u].find(v) != adjList[u].end())
            return true;
        return false;
    }

    void addVertex() // req = 1
    {
        cin >> v;
        if (adjList.find(v) != adjList.end())
        {
            cout << "DUP\n";
        }
        else
        {
            adjList[v] = unordered_map<string, bool>();
            cout << "ADD\n";
        }
        return;
    }

    void addEdge()   // req = 2
    {
        cin >> u >> v;
        bool Uexist = adjList.find(u) != adjList.end();
        bool Vexist = adjList.find(v) != adjList.end();

        if (!Uexist) // neu u chua co trong G, them u
            adjList[u] = unordered_map<string, bool>();
        if (!Vexist) // neu v chua co trong G, them u
            adjList[v] = unordered_map<string, bool>();

        // them cac dinh xong thi them canh -> ADD2
        if (!Uexist || !Vexist)
        {
            adjList[u][v] = 1;
            cout << "ADD2\n";
            return;
        }

        // da co 2 dinh, them canh vao
        // neu canh da co trong do thi -> DUP2
        if (adjList[u].find(v) != adjList[u].end())
        {
            cout << "DUP2\n";
            return;
        }
        // neu canh chua co trong do thi -> ADD3
        else
        {
            cout << "ADD3\n";
            adjList[u][v] = 1;
            return;
        }
    }

    void checkAdj() // req == 3
    {
        cin >> u >> v;
        if (adjList.find(u) == adjList.end() || adjList[u].find(v) == adjList[u].end() ) // neu u ko co trong G || v khong ke u
        {
            cout << "FALSE\n";
            return;
        }

        cout << "TRUE\n";
        return;
    }

    void adj()
    {
        cin >> v;
        // NEU CHUA CO TRONG G -> 0
        if (adjList.find(v) == adjList.end())
        {
            cout << 0 << endl;
            return;
        }
        // neu v co trong G -> xuat so luong dinh ke
        cout << adjList[v].size() << endl;
        return;
    }

    void process()
    {
        int req;
        while (true)
        {
            cin >> req;
            if (req == 0)
                break;
            else if (req == 1)
                this->addVertex();
            else if (req == 2)
                this->addEdge();
            else if (req == 3)
                this->checkAdj();
            else if (req == 4)
                this->adj();
        }
        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph G;
    G.process();
    return 0;
}