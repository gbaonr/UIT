#include <bits/stdc++.h>
using namespace std;

vector<int> times;
vector<int> perm, res, total;
int n, m;
int minCost = 0;

void find(int idxTask)
{
    for (int i = 0; i < m; i++) {
        total[i] += times[idxTask];
        perm[idxTask] = i;

        if (idxTask == n - 1) {
            int cur = *max_element(total.begin(), total.end());
            if (cur < minCost) {
                minCost = cur;
                res = perm;
                cout << maxCost << endl;
            }
        } else {
            find(idxTask + 1);
        }

        total[i] -= times[idxTask];
    }
}

int main()
{
    cin >> n >> m;

    times.assign(n, 0);
    perm.assign(n, 0);
    total.assign(m, 0);

    for (auto& t : times)
        cin >> t;

    find(0);

    for (auto& p : res)
        cout << p << " ";
}