#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

double EPS = 1e-6;

void find(int cur, double need, double& total, vector<double>& res, vector<int>& heso)
{
    for (double i = 0.25; i <= 10; i += 0.25) {
        res[cur] = i;
        double lastTotal = total;

        total += i * heso[cur] / 100;
        double round_total = floor(total * 10 + 0.5 + EPS) / 10.0;

        if (round_total <= need) {
            if (cur == heso.size() - 1) {
                if (abs(round_total - need) <= EPS) {
                    for (auto& v : res) {
                        printf("%.3g ", v);
                    }
                    printf("\n");
                }
            } else {
                find(cur + 1, need, total, res, heso);
            }

            total = lastTotal;
        } else {
            total = lastTotal;
            break;
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

    double need, total = 0;
    cin >> need;

    vector<double> res(n);
    find(0, need, total, res, heso);
}