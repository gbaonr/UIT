#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int l, int r)
{
    int p = a[(l + r) >> 1];
    int t = l;

    for (int j = l; j <= r; j++)
        if (a[j] <= p)
            swap(a[t++], a[j]);

    swap(a[t], a[r]);
    return t;
}

int search(int n, int k, vector<int>& a, int l, int r)
{
    int pivot = partition(a, l, r);

    if (pivot - l == k - 1) {
        return a[pivot];
    } else if (pivot - l > k - 1) {
        return search(n, k, a, l, pivot - 1);
    } else {
        return search(n, k - pivot + l - 1, a, pivot + 1, r);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << search(n, n - k + 1, a, 0, n - 1);
}