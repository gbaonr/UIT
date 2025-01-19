#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int need;
    cin >> need;

    vector<int> heso(n);
    for (auto& v : heso)
        cin >> v;

    vector<float> res(n);
    find(0, need, res);
}