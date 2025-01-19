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
    vector<int> last(accumulate(a.begin(), a.end(), 0) + 1, -1);

    for (int i = 0; i < a.size(); i++) {
        res[a[i]] = true;

        if (~last[a[i]])
            last[a[i]] = min(last[a[i]], i);
        else
            last[a[i]] = i;
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    for (int i = 0; i < last.size(); i++)
        cout << last[i] << " ";
    cout << endl;

    for (int i = 1; i < res.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (i < a[j])
                continue;

            if (j <= last[i - a[j]]) {
                // cout << "j: " << j << " last: " << last[i - a[j]] << endl;
                continue;
            }

            cout << i << " " << j << " " << res[i - a[j]] << endl;

            if (res[i - a[j]]) {
                // if (i == 10) {
                //     cout << "i: " << i << endl;
                //     cout << "j: " << j << endl;

                //     for (int i = 0; i < res.size(); i++)
                //         cout << res[i] << " ";
                //     cout << endl;
                //     for (int i = 0; i < last.size(); i++)
                //         cout << last[i] << " ";
                //     cout << endl;
                // }
                res[i] = true;
                last[i] = j;
                break;
            }
        }
    }

    cout << accumulate(res.begin(), res.end(), 0) << endl;
    for (int i = 0; i < res.size(); i++)
        if (res[i])
            cout << i << " ";
}