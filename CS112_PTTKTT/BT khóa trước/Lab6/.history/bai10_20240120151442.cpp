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

    vector<bool> dp(accumulate(a.begin(), a.end(), 0) + 1, false);
    vector<int> last(accumulate(a.begin(), a.end(), 0) + 1, -1);

    // a[i]   = 2 2 4 5
    // sum    = 13
    // res    = {  0,  0, 1, 0,  1, 1, 0,  0,  0,  0,  0,  0,  0,  0 }
    // last   = { -1, -1, 0, 0, -1, 2, 3, -1, -1, -1, -1, -1, -1, -1 }
    for (int i = 0; i < a.size(); i++) {
        dp[a[i]] = true;

        if (last[a[i]] != -1)
            last[a[i]] = max(last[a[i]], i);
        else
            last[a[i]] = i;
    }

    // i la cac gia tri co the dat duoc
    for (int i = 1; i < dp.size(); i++) {
        // xet tung gia tri trong a
        for (int j = 0; j < a.size(); j++) {
            // neu i < a[j], tuc la khong the dat duoc gia tri i
            // neu su dung gia tri a[j] -> co the bo qua
            if (i < a[j])
                continue;

            // i = x + a[j] // vi the ta can xem xet cac gia tri x = i - a[j]
            // first[i - a[j]] la vi tri dau tien cua gia tri i - a[j] trong a
            // kiem tra j <= first[i - a[j]] de su dung cac gia a[i] ma i > j
            // tranh trung lap nhu 2 + 4 va 4 + 2
            if (j <= last[i - a[j]])
                continue;

            if (dp[i - a[j]]) {
                dp[i] = true;
                last[i] = j;
                break;
            }
        }
    }

    cout << accumulate(dp.begin(), dp.end(), 0) << endl;
    for (int i = 0; i < dp.size(); i++)
        if (dp[i])
            cout << i << " ";
}