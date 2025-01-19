#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<int, int, int>> a;
vector<int> nextProject;

// int dpFunc(int i)
// {
//     // return max(
//     // dpFunc(i + 1));
//     return 0;
// }

int main()
{
    cin >> n;

    for (int i = 0, x, y, z; i < n; i++) {
        cin >> x >> y >> z;
        a.push_back({ x, y, z });
    }

    sort(a.begin(), a.end(), [](auto& l, auto& r) {
        return get<1>(l) < get<1>(r);
    });

    nextProject.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {

        }
    }
}