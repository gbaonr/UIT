#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

float EPS = 1e-6;

void find(int cur, float need, float total, vector<float>& res, vector<int>& heso)
{
    for (float i = 0.25; i <= 10; i += 0.25) {
        total += i / 100 * heso[cur];
        if (cur == heso.size() - 1) {
            total = round(total * 10) / 10;
            cout << total << " ";

            if (abs(total - need) <= EPS) {
                for (auto& v : res) {
                    printf("%.2f", v);
                }
                printf("\n");
            }
        } else {
            find(cur + 1, need, total, res, heso);
        }
        total -= i / 100 * heso[cur];
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
    find(0, need, 0, res, heso);
}