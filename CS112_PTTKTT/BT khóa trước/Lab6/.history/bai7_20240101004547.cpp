#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> page, price;

void find(int i, int cur)
{
    int res = 0;

    if (cur + price[i] <= x)
        res = page[i] + find(i + 1, cur + price[i]);
}

int main()
{
    cin >> n >> x;

    price.resize(n + 1);
    page.resize(n + 1);

    for (auto& v : price)
        cin >> v;

    for (auto& v : page)
        cin >> v;
}