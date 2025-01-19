#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int l, int r)
{
    int pivot = a[(l + r) >> 1];
    int i = l;

    for (int j = l; j <= r; j++)
        if (a[j] <= pivot)
            swap(a[i++], a[j]);

    swap(a[i], a[r]);
    return i;
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