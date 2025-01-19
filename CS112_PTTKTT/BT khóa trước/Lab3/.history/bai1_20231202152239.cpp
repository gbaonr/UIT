#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, temp;
    cin >> n >> m;

    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        jobs.push_back({ i, temp });
    }

    vector<int> machines(m);
    vector<int> sol(n);

    sort(jobs.begin(), jobs.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });

    for (int i = 0; i < n; ++i) {
        int minIndex = min_element(machines.begin(), machines.end()) - machines.begin();
    }
}