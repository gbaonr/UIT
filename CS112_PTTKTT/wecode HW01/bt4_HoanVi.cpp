#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>

using namespace std;
void print_(vector<int> res){
    for (auto iter:res){
        cout << iter ;
    }
    cout << "\n";
}

void hoanvi(int n, int k, map<int, bool> number, vector<int> res)
{
    for (auto iter = number.rbegin(); iter != number.rend(); ++iter)
    {
        if (iter->second == 0){
            res.push_back(iter->first);
            iter->second = 1;
            if (k == n)
                print_(res);
            else
                hoanvi(n, k+1, number, res);

            res.pop_back();
            iter->second = 0;
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int, bool> number;
    vector<int> res;

    while (n != 0){
        number[n%10] = 0;
        n = n/10;
    }

    hoanvi(number.size(), 1, number, res);
    
    return 0;
}   

