#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (auto& v : a)
        cin >> v;

    vector<bool> res(accumulate(a.begin(), a.end(), 0) + 1, false);
    for (auto& v : a)
        res[v] = true;

    for (int i = 1; i < res.size(); i++)
        for (auto& v : a)
            res[i] = res[i] | ((i >= v) && res[i - v]);

    for (int i = 0; i < res.size(); i++)
        if (res[i])
            cout << i << " ";
}