#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertex, q;
    cin >> vertex >> q;

    vector<string> vertices(vertex);
    unordered_map<string, unordered_map<string, int>> graph; // luu (a, b, c) - duong a -> b voi trong so la c

    // nhap cac dinh
    for (auto& v : vertices)
        cin >> v;

    // nhap do thi ke
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            int w;
            cin >> w;
            graph[vertices[i]][vertices[j]] = w; // luu trong so giua 2 dinh
        }
    }

    while (q--) {
        string s, d; // dinh bat dau va dinh ket thuc
        cin >> s >> d;

        queue<string> pq; // luu cac dinh can xet
        unordered_map<string, bool> close, open; // luu cac dinh da xet
        unordered_map<string, string> prev; // luu dinh cha cua dinh dang xet
        unordered_map<string, int> dist; // luu khoang cach
        unordered_map<string, int> level;
        int totalOpen = 0; // luu so dinh da duoc phat trien
        bool found = false; // neu tim thay duong di thi found = true

        pq.push(s); // them s vao stack
        dist[s] = 0; // khoang cach bat dau tu s la 0
        level[s] = 0;
        open[s] = true;

        while (!pq.empty()) { // trong khi van con dinh can xet
            string p = pq.front(); // lay dinh can xet
            pq.pop(); // xoa dinh

            if (close[p]) // neu dinh da xet thi bo qua
                continue;

            totalOpen++; // tang so dinh da duoc phat trien
            close[p] = true; // danh dau dinh da xet

            cout << p << " " << level[p] << endl;

            if (p == d) { // neu dinh can xet la dinh ket thuc thi ket thuc + in ra duong di
                string path = "";
                while (p != s) {
                    path = p + " " + path;
                    p = prev[p];
                }
                path = s + " " + path;

                cout << path << endl;
                cout << totalOpen << " " << dist[d] << endl;

                found = true;
                break;
            }

            for (auto& v : vertices) { // xet cac dinh ke cua p, v la dinh ke
                auto w = graph[p][v]; // w la khoang cach tu p den v

                // neu khong co canh noi giua p va v thi bo qua
                if (w == 0)
                    continue;

                if (open[v])
                    continue;

                if (!close[v]) { // neu v chua xet thi them vao stack
                    pq.push(v);
                    prev[v] = p; // gan dinh cha cua v la p
                    dist[v] = dist[p] + w; // gan khoang cach tu p den v
                    level[v] = level[p] + 1;
                    open[v] = true;
                }
            }
        }

        if (!found) {
            cout << "-unreachable-\n";
            cout << totalOpen << " " << 0 << endl;
        }
    }
}