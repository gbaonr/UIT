#include <bits/stdc++.h>
using namespace std;

vector<int> h, d;
int n, q;

void dfs()
{
}

int main()
{
    cin >> n >> q;

    h.assign(n, 0);
    d.assign(n, 0);

    for (int i = 0, a, b; i < n; ++i) {
        cin >> a >> b;
        --a, --b;
    }

    // ta co n dinh, va n - 1, lien thong => tree
}