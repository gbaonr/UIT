#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

float EPS = 1e-6;

void find(int cur, float need, float total, vector<float>& res, vector<int>& heso)
{
    for (float i = 0.25; i <= 10; i += 0.25) {
        total += i * heso[cur] / 100;
        if (cur == heso.size() - 1) {
            total = round(total * 10) / 10;
            if (total > 9)
                cout << total << " " << need << '\n';

            if (abs(total - need) <= EPS) {
                for (auto& v : res) {
                    printf("%.2f", v);
                }
                printf("\n");
            }
        } else {
            find(cur + 1, need, total, res, heso);
        }
        total -= i * heso[cur] / 100;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> heso(n);
    for (auto& v : heso)
        cin >> v;

    float need;
    cin >> need;

    vector<float> res(n);
    find(0, need, 0, res, heso);
}