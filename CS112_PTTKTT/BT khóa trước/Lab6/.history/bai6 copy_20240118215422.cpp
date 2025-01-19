#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<int, int, int>> a;

void dpFunc(int i)
{
}

int main()
{
    cin >> n;

    for (int i = 0, x, y, z; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a.push_back({ x, y, z });
    }

    sort(a.begin(), a.end(), [](auto& l, auto& r) {
        return get<1>(l) < get<1>(r);
    });
}