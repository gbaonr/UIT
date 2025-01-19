#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int left, int right)
{
    int mid = a[(left + right) >> 1];
    int temp = left;

    for (int j = left; j <= right; j++)
        if (a[j] <= mid)
            swap(a[temp++], a[j]);

    swap(a[temp], a[right]);
    return temp;
}

int search(int n, int k, vector<int>& a, int l, int r)
{
    int pivot = partition(a, l, r);

    if (pivot - l == k - 1)
        return a[pivot];

    if (pivot - l > k - 1)
        return search(n, k, a, l, pivot - 1);

    return search(n, k - pivot + l - 1, a, pivot + 1, r);
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto& v : a)
        cin >> v;

    auto res = search(n, n - k + 1, a, 0, n - 1);
    cout << res;
}