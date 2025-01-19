#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n), last(n);

    for (auto& v : a)
        cin >> v;

    vector<bool> res(accumulate(a.begin(), a.end(), 0) + 1, false);
    for (int i = 0; i < a.size(); i++) {
        res[a[i]] = true;
        last[a[i]] = i;
    }

    for (int i = 1; i < res.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (i < a[j])
                continue;

            if (j < last[i - a[j]])
                continue;

            if (res[i - a[j]]) {
                res[i] = true;
                last[i] = j;
                break;
            }
        }
        // for (auto& v : a) {
        //     if (v < last[i])
        //         continue;

        //     if (i < v)
        //         continue;

        //     res[i] = res[i] | ((i >= v) && res[i - v]);
        // }
    }

    cout << accumulate(res.begin(), res.end(), 0) << endl;
    for (int i = 0; i < res.size(); i++)
        if (res[i])
            cout << i << " ";
}