#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertex, q;
    cin >> vertex >> q;

    vector<string> vertices(vertex);
    unordered_map<string, unordered_map<string, int>> graph;

    for (auto& v : vertices)
        cin >> v;

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            int w;
            cin >> w;
            graph[vertices[i]][vertices[j]] = w;
        }
    }

    while (q--) {
        string s, d; // dinh bat dau va dinh ket thuc
        cin >> s >> d;

        stack<string> open; // luu cac dinh can xet
        unordered_map<string, bool> close; // luu cac dinh da xet
        unordered_map<string, string> prev; // luu dinh cha cua dinh dang xet
        unordered_map<string, int> dist; // luu khoang cach
        int totalOpen = 0; // luu so dinh da duoc phat trien

        while (!open.empty()) { // trong khi van con dinh can xet
            string p = open.top(); // lay dinh can xet
            open.pop(); // xoa dinh
            totalOpen++; // tang so dinh da duoc phat trien

            if (p == d) { // neu dinh can xet la dinh ket thuc thi ket thuc + in ra duong di
                string path = "";
                while (p != s) {
                    path = p + " " + path;
                    p = prev[p];
                }
                cout << path << endl;
                cout << totalOpen << dist[d] << endl;

                break;
            }

            close[p] = true; // danh dau dinh nay da xet

            for (auto& [v, w] : graph[p]) { // xet cac dinh ke cua p, v la dinh ke, w la trong so
                if (!close[v]) { // neu v chua xet thi them vao stack
                    open.push(v);
                    prev[v] = p; // gan dinh cha cua v la p
                    dist[v] = dist[p] + w; // gan khoang cach tu p den v
                }
            }
        }
    }
}