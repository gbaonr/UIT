#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int partition(int left, int right)
{
    // chon phan tu mid lam pivot
    int mid = a[(left + right) >> 1];
    int temp = left;

    // dua cac phan tu nho hon mid ve ben trai
    for (int i = left; i <= right; i++)
        if (a[i] <= mid)
            swap(a[temp++], a[i]);

    // swap(a[temp], a[right]);
    return temp;
}

int search(int k, int l, int r)
{
    int pivot = partition(l, r);

    if (pivot - l == k - 1)
        return a[pivot];

    if (pivot - l > k - 1)
        return search(k, l, pivot - 1);

    return search(k - pivot + l - 1, pivot + 1, r);
}

int main()
{
    // nhap n va k
    int k;
    cin >> n >> k;

    // nhap cac gia tri a[i]
    a.assign(n, 0);
    for (auto& v : a)
        cin >> v;

    auto res = search(n - k + 1, 0, n - 1);
    cout << res;
}