#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> res;
vector<bool> used;

// cur - index res dang xet
void find(int cur)
{
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            res[cur] = i;
            cout << i << " ";

            if (cur == n - 1) {
                cout << endl;
            } else {
                find(cur + 1);
            }

            used[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    res.assign(n, 0);
    used.assign(n + 1, false);

    find(0);

    return 0;
}