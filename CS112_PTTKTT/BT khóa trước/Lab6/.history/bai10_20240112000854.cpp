#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (auto& v : a)
        cin >> v;

    vector<int> res(accumulate(a.begin(), a.end(), 0) + 1, 0);
}