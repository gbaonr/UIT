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

    nextProject.resize(n);

    for (int i = 0; i < n; ++i) {
        int curEnd = get<1>(a[i]);

        int l = i + 1;
        int r = n - 1;
        int m = -1;

        while (l <= r) {
            m = (l + r) >> 1;
            int start = get<0>(a[m]);

            if (start > curEnd) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        cout << " " << m << " " << get<0>(a[m]) << " " << curEnd << "\n";
        if (m >= 0 && get<0>(a[m]) <= curEnd) {
            m = -1;
        }

        cout << i << " " << m << endl;
    }
}