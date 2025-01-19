#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> res;

void find(int cur)
{
    for (int i = 1; i <= n; ++i) {
        res[cur] = i;
        if (cur == n - 1) {
            for (auto& v : res)
                cout << v << " ";
            cout << endl;
        } else {
            find(cur + 1);
        }
    }
}

int main()
{
    cin >> n;
    res.assign(n, 0);

    find(0);

    return 0;
}