#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<tuple<int, int, int>> a;

    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a.push_back({ x, y, z });
    }

    sort(a.begin(), a.end(), [](auto& l, auto& r) {
        return get<1>(l) < get<1>(r);
    });

    vector<int> dp(n);

    for (int i = 0; i < n; ++i) {
        if (i) {
            int j = i - 1;

            while (j >= 0) {
                if (get<1>(a[j]) < get<0>(a[i]))
                    break;

                --j;
            }

            if (~j) {}
            dp[i] = max(dp[i - 1], dp[j] + get<2>(a[i]));
        } else {
            
        }
    }
}