#include <iostream>
#include <vector>
using namespace std;

// cur - index res dang xet
void find(int cur, int n, vector<int>& res, vector<bool>& used)
{
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            used[i] = true;
            res[cur] = i;

            if (cur == n - 1) {
                for (auto& v : res)
                    cout << v << " ";
                cout << "\n";
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

    int n;
    vector<int> res;
    vector<bool> used;


    cin >> n;
    res.assign(n, 0);
    used.assign(n + 1, false);

    find(0);

    return 0;
}