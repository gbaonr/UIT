#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 100005;
const int LOG = 17; // Vì n <= 100000, nên log2(100000) khoảng 17.

vector<int> adj[MAXN];
int depth[MAXN];
int parent[MAXN][LOG];

// Hàm DFS để tính độ sâu và khởi tạo bảng cha
void dfs(int v, int p)
{
    parent[v][0] = p;
    for (int i = 1; i < LOG; ++i)
    {
        if (parent[v][i - 1] != -1)
        {
            parent[v][i] = parent[parent[v][i - 1]][i - 1];
        }
        else
        {
            parent[v][i] = -1;
        }
    }

    for (int u : adj[v])
    {
        if (u != p)
        {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

// Hàm tìm LCA của hai đỉnh u và v
int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    // Đưa u và v về cùng độ sâu
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; ++i)
    {
        if ((diff >> i) & 1)
        {
            u = parent[u][i];
        }
    }

    if (u == v)
        return u;

    for (int i = LOG - 1; i >= 0; --i)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

// Hàm tính khoảng cách giữa hai đỉnh u và v
int distance(int u, int v)
{
    int l = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
}

int main()
{
    int n, q;
    cin >> n >> q;

    // Đọc các cạnh của cây
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Khởi tạo các giá trị ban đầu
    depth[1] = 0;
    parent[1][0] = -1;
    dfs(1, -1);

    // Xử lý các truy vấn
    for (int i = 0; i < q; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << distance(a, b) << endl;
    }

    return 0;
}
