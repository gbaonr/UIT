#include <bits/stdc++.h>
using namespace std;

/*
- Them: them gia tri m[j] --> j + 1
- Thay the: thay n[i] = m[j] --> i + 1, j + 1
- Xoa: xoa n[i] --> i + 1
*/

string a, b;

int dpFunc(int i, int j)
{
    if (a[i] == b[j]) {
        return dpFunc(i + 1, j + 1);
    }

    return 1 + min({ dpFunc(i + 1, j), dpFunc(i, j + 1), dpFunc(i + 1, j + 1) });
}

int main()
{
    cin >> a >> b;
}