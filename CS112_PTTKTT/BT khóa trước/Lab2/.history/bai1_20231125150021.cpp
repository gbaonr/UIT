#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> res;
vector<bool> used;

// cur - index res dang xet
void find(int cur)
{
    for (int i = cur + 1; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            res[cur] = i;

            if (cur == n - 1) {
                for (auto& v : res)
                    cout << v << " ";
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    res.assign(n + 1, 0);
    used.assign(n + 1, false);

    find(0);

    return 0;
}