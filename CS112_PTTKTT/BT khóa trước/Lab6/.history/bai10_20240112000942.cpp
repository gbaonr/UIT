#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (auto& v : a)
        cin >> v;

    vector<bool> res(accumulate(a.begin(), a.end(), 0) + 1, 0);
    for (auto &v : a)
        res[v] = 1;

    for (int i = 1; i < res.size(); i++)
}