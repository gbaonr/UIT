#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

// Ham split se chia mang a thanh 2 phan
int split(int left, int right)
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

int search(int l, int r, int k)
{
    // neu l == r, tuc la chi con 1 phan tu
    // tra ve phan tu do
    if (l == r)
        return a[l];

    // chia mang thanh 2 phan
    // pivot la index cua phan tu chia mang thanh 2 phan
    int pivot = split(l, r);

    cout << pivot << endl;
    for (int i = l; i <= r; ++i)
        cout << a[i] << " ";

    cout << endl;

    // z la so phan tu ben trai pivot
    int z = pivot - l + 1;

    // neu k == z, tuc la phan tu nho nhat thu k la pivot
    if (z == k)
        return a[pivot];

    // neu k > z, tuc la phan tu nho nhat thu k nam o ben phai pivot
    // ta se tim kiem trong mang con ben phai pivot
    // bay gio ta can tim phan tu nho nhat thu k - z
    // vi ben trai pivot co z phan tu nho hon
    if (k > z)
        return search(pivot + 1, r, k - z);

    // neu k < z, tuc la phan tu nho nhat thu k nam o ben trai pivot
    // ta se tim kiem trong mang con ben trai pivot
    // tu l -> pivot - 1
    return search(l, pivot - 1, k);
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

    auto res = search(0, n - 1, k);
    cout << res;
}