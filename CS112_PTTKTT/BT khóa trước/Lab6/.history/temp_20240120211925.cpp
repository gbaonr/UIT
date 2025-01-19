#include <iostream>
#include <vector>
using namespace std;

vector<int> h, par; // h[x] la chieu cao cua x, par[x] la node cha cua x
vector<vector<int>> g; // danh sach ke
vector<bool> used; // danh dau cac node da duyet
int n, q; // n la so dinh, q la so query

// su dung dfs de tinh h[x] va par[x]
void dfs(int x)
{
    // danh dau x la da duyet
    used[x] = true;

    // duyet cac dinh ke cua x
    for (auto& v : g[x]) {
        // neu v chua duoc duyet
        if (!used[v]) {
            h[v] = h[x] + 1; // chieu cao cua v = chieu cao cua x + 1
            par[v] = x; // node cha cua v la x
            dfs(v); // duyet tiep tuc tu v
        }
    }
}

int LCA(int u, int v)
{
    // u, v la 2 dinh can tim LCA
    // h[x] la chieu cao cua x
    // par[x] la node cha cua x
    while (u != v) {
        if (h[u] > h[v]) {
            u = par[u];
        } else {
            v = par[v];
        }
    }

    return u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // nhap n va q
    cin >> n >> q;

    // khoi tao cac bien
    h.assign(n, 0);
    g.assign(n, vector<int>());
    used.assign(n, false);
    par.assign(n, 0);

    // nhap cac canh cua cay
    for (int i = 0, a, b; i < n - 1; ++i) {
        cin >> a >> b;
        --a, --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    // gia su 0 la goc cua cay --> h[0] = 1, par[0] = 0
    h[0] = 1;
    par[0] = 0;

    dfs(0);

    for (int i = 0, a, b; i < q; ++i) {
        cin >> a >> b;
        --a, --b;

        // tim node cha chung
        int u = a, v = b;
        // cout << "u = " << u << " v = " << v << " " << a << " " << b << "\n";

        while (u != v) {
            if (h[u] > h[v]) {
                u = par[u];
            } else {
                v = par[v];
            }
        }

        cout << h[a] + h[b] - 2 * h[u] << "\n";
    }
}