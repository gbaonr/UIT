#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> page, price;

void find() { }

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