#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

float EPS = 1e-6;

void find(int cur, float need, float& total, vector<float>& res, vector<int>& heso)
{
    for (float i = 0.25; i <= 10; i += 0.25) {
        res[cur] = i;
        total += i * heso[cur] / 100;
        round_total = 1.0 * round(total * 10 + 0.5) / 10;

        if (round_total <= need) {
            if (cur == heso.size() - 1) {
                if (abs(total - need) <= EPS) {
                    for (auto& v : res) {
                        printf("%.3g ", v);
                    }
                    printf("\n");
                }
            } else if (round_total == need) {
                find(cur + 1, need, total, , heso);
            }
        } else {
            find(cur + 1, need, res, heso);
        }
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
    find(0, need, res, heso);
}