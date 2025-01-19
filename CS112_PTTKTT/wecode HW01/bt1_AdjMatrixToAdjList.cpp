#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int tmp;
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            if (tmp == 1)
                adj_list[i].push_back(j+1);
        }
    }
    for (int i = 0; i < n; i++){
        if (adj_list[i].empty())
            continue;
        cout << i+1 << "->";
        for (auto iter:adj_list[i])
            cout << iter << " "; 
        cout << endl;
    }
}