#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n, q;
    cin >> n >> q;
    vector<long> a(n);      // mang chua cac so nguyen
    vector<long> sum(n, 0); // mang chua tong cac so nguyen

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
        {
            sum[i] = a[i];
        }
        else
        {
            sum[i] = sum[i - 1] + a[i];
        }
    }
    
    int idx1, idx2;
    for (int i = 0; i < q; i++)
    {
        cin >> idx1 >> idx2;
        // cout << sum[idx2 - 1] - sum[idx1 - 1] + a[idx1 - 1] << endl;
        cout << sum[idx2 - 1] - sum[idx1 - 1] + a[idx1 - 1] << endl;
    }
}