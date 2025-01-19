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
            res[cur] = i;

            // neu xet du n phan tu thi in ra
            if (cur == n - 1) {
                for (auto& v : res)
                    cout << v << " ";
                cout << endl;
            } else {
                find(cur + 1);
            }
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