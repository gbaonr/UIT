#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    // input map
    map<int, int> adj;

    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a][b] = 1;
    }

    // input request
    vector<int> start(q);
    vector<int> end(q);

    for (int i = 0; i < q; i++)
    {
        cin >> start[i] >> end[i];
    }

    // dynamic planning
    vector<vector<int>> table(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                table[i][j] = 0;
            }
            // neu start ke voi end
            else if (adj[i][j] == 1)
            {
                table[i][j] = 1;
            }
            else
            {
                table[i][j] =
            }
        }
    }
}