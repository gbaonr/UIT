#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int selectMachine(vector<int> machines){
    int idx = 0;
    int minTime = INT_MAX;
    for (int i = 0; i < machines.size(); i++){
        if (machines[i] <= minTime){
            minTime = machines[i];
            idx = i;
        }
    }
    return idx;
}

void planning(vector<pair<int, int>> jobs, vector<int>& machines, vector<int>& res){
    for (int i = 0; i < jobs.size(); i++){
        int machine_idx = selectMachine(machines);
        res[jobs[i].second] = machine_idx;
        machines[machine_idx] += jobs[i].first;
    }
}

bool cmp(pair<int, int>& a, pair<int, int>& b){
    return a.first > b.first;
}

int main(){
    int n, m; //n = jobs num, m = machines num
    cin >> n >> m;
    vector<pair<int,int>> jobs;
    vector<int> machines (m, 0);
    int time;
    for (int i = 0; i < n; i++){
        cin >> time;
        jobs.push_back({time,i});
    }
    vector<int> res (n, -1);


    // sort lai jobs theo thu tu tgian giam dan
    sort(jobs.begin(), jobs.end(), cmp);

    planning(jobs, machines, res);
    
    for (auto iter : res){
        cout << iter << " ";
    }

    // sort(machines.begin(), machines.end());
    // cout << "\nMAX time = " << machines[2];

}