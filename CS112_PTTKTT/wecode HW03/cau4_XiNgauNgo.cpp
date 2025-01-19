#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long count = 0;

long long dynamic_planning(long long s, vector<long long> &res)
{
    long long ans = 1;
    long long k = 0;
    long long MOD = 1e9 + 7;

    res.push_back(1);
    for (long long i = 1; i <= s; i++)
    {

        ans = 0;
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
            {
                ans += res[i - j];
            }
        }
        res.push_back(ans % MOD);
    }
    // print(res);
    return res.back();
}

int main()
{
    long long s;
    // cout << "Nhap s: ";
    cin >> s;
    vector<long long> res;
    cout << dynamic_planning(s, res);
    // cout << pow(2, s);
}

void print(const vector<long long> &res)
{
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;
}
