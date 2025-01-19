#include <bits/stdc++.h>
using namespace std;

vector<int> times;
vector<int> perm, res, total;
int n, m;
int minCost = 2e9;

void find(int idxTask)
{
    for (int i = 0; i < m; i++) {
        total[i] += times[idxTask];

        if (idxTask == n - 1) {
            int cur = *min_element(total.begin(), total.end());
            if (cur < minCost) {
                minCost = cur;
                // res = ;
            }

        } else {
            find(idxTask + 1);
        }
    }
}

int main()
{
    cin >> n >> m;

    times.resize(n);
    perm.resize(n);

    for (auto& t : times)
        cin >> t;

    find(0);

    for ()
}