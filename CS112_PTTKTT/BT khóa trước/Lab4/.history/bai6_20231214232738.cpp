#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    map<string, map<string, int>> graph;
    for (int i = 0; i < n; i++) {
        string u, v;
        int w;

        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    auto find = [&]() {

    }
}