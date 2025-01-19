#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int partition(int left, int right)
{
    int temp = left;

    // chon phan tu cuoi cung lam pivot va
    // dua cac phan tu nho hon mid ve ben trai
    // cac phan tu lon hon mid ve ben phai
    for (int i = left, p = a[right]; i < right; i++)
        if (a[i] <= p)
            swap(a[temp++], a[i]);

    // luc nay chi swap a[right] voi a[temp] la
    // ta co mang a duoc chia thanh 2 phan
    // va tra ve chi so cua pivot
    return swap(a[temp], a[right]), temp;
}

int search(int k, int l, int r)
{
    // neu l == r, tuc la chi con 1 phan tu
    // tra ve phan tu do
    if (l == r)
        return a[l];

    // chia mang thanh 2 phan
    // pivot la index cua phan tu chia mang thanh 2 phan
    int pivot = partition(l, r);

    // z = pivot - l + 1 la so phan tu ben trai pivot
    // tuc z la so phan tu nho hon pivot
    // neu k == z, tuc la pivot la phan tu nho nhat thu k
    if (pivot - l + 1 == k)
        return a[pivot];

    if (k < pivot - l + 1)
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

    k = n - k + 1;

    auto res = search(k, 0, n - 1);
    cout << res;
}