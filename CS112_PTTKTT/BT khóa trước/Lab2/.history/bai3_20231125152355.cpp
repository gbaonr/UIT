#include <iostream>
#include <vector>
using namespace std;

float EPS = 1e-6;

void find(int cur, float need, float& total, vector<float>& res, vector<int>& heso)
{
    for (float i = 0.25; i <= 10 + EPS; i += 0.25) {
        float last_total = total;
    }
}

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
    find(0, need, res, heso);
}