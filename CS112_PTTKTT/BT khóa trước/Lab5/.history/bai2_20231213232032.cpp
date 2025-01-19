#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    string s, d;
    cin >> s >> d;

    vector<string> vertex(v);
    for (auto& x : vertex) {
        cin >> x;
    }

    vector<int> cost(v);
    for (auto& x : cost) {
        cin >> x;
    }

    map<string, map<string, int>> g;
}