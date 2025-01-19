#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int q;
    string u, v;
    unordered_map<string, unordered_map<string, bool>> adj;

    while (1) {
        cin >> q;

        if (q == 0) break;
        if (q == 1) {
            cin >> u;
            if (adj.find(u) != adj.end()) {
                cout << "DUP" << '\n';
                continue;
            }
            adj[u] = unordered_map<string, bool>();  
            cout << "ADD" << '\n';
            continue;
        }
        if (q == 2) {
            cin >> u >> v;

            bool a = adj.find(u) == adj.end();
            bool b = adj.find(v) == adj.end();

            if (a || b) {
                if (a) 
                    adj[u] = unordered_map<string, bool>();

                if (b)
                    adj[v] = unordered_map<string, bool>();

                adj[u][v] = 1;
                cout << "ADD2" << '\n';
            } else {
                if (adj[u].find(v) == adj[u].end()) {
                    cout << "ADD3" << '\n';
                    adj[u][v] = 1;
                } else {
                    cout << "DUP2" << '\n';
                }
            }
            continue;
        }
        if (q == 3) {
            cin >> u >> v;
            cout << ((!adj[u][v]) ? "FALSE" : "TRUE") << '\n';
            continue;
        }
        if (q == 4) {
            cin >> u;
            if (adj.find(u) == adj.end()) {
                cout << 0 << '\n';
                continue;
            }
            cout << adj[u].size() << '\n';
        }
    }
}