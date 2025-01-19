#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (auto& v : a)
        cin >> v;

    sort(a.begin(), a.end());

    vector<bool> res(accumulate(a.begin(), a.end(), 0) + 1, false);
    vector<int> last(accumulate(a.begin(), a.end(), 0) + 1, -1);

    for (int i = 0; i < a.size(); i++) {
        res[a[i]] = true;

        if (last[a[i]] != -1)
            last[a[i]] = min(last[a[i]], i);
        else
            last[a[i]] = i;
    }

    // i la cac gia tri co the dat duoc
    for (int i = 1; i < res.size(); i++) {
        // xet tung gia tri trong a
        for (int j = 0; j < a.size(); j++) {
            // neu i < a[j], tuc la khong the dat duoc gia tri i
            // neu su dung gia tri a[j] -> co the bo qua
            if (i < a[j])
                continue;

            if (j <= last[i - a[j]]) {
                continue;
            }

            if (res[i - a[j]]) {
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