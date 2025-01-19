#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

void print_(vector<int> res){
    for (auto iter:res){
        cout << iter << " ";
    }
    cout << "\n";
}


void planning(int n, int m, vector<vector<int>> jobs, vector<int>& machines, vector<int>& res){
    for (int i = 0; i < n; i++){
        int minTime = 99999;
        int idx = 0;
        for (int j = 0; j < m; j++){
            if (jobs[j][i] < minTime && jobs[j][i] >= 0 ){
                idx = j;
                minTime = jobs[j][i];
            }
            else if (jobs[j][i] == minTime){ // time = nhau -> chon may co tong tgian nho nhat
                if (machines[j] <= machines[idx]){
                    idx = j;
                    minTime = jobs[j][i];
                }
            }
        }
        machines[idx] += minTime;
        res[i] = idx;
    }
}

int main(){
    int n, m; //n = jobs num, m = machines num
    cin >> n >> m;
    vector<vector<int>> jobs(m);
    vector<int> machines (m, 0);
    vector<int> res (n, -1);

    // input time of each job for each machine
    int time;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> time;
            jobs[i].push_back(time);
        }
    }

    planning(n, m, jobs, machines, res);

    cout << "\n\n";
    print_(res);
}