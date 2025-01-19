#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

vector<int> optimal = {1, 2, 1, 1, 0, 2, 1, 0};
vector<int> optimal2 = {1, 0, 0, 1, 0, 1, 0, 0};

int countTime(vector<int> jobs, vector<int> res, int m){
    vector<int> machines (m, 0);
    for (int i = 0; i < res.size(); i++){
        machines[res[i]] += jobs[i];
    }
    return *min_element(machines.begin(), machines.end());
}

void print_(vector<int> res){
    for (auto iter: res){
        cout << iter << " ";
    }
    cout << endl;
}

void minPlanning(int k, int& bestTime, int sumTime, vector<int> jobs, vector<int>& machines, vector<int>& ans, vector<int>& finalAns){
    for (int i = 0; i < machines.size(); i++){
        int jobTime = jobs[k];
        machines[i] += jobTime;
        ans.push_back(i);

        if (k + 1== jobs.size()){
            int maxTime = *max_element(machines.begin(), machines.end());
            if (maxTime <= bestTime){
                bestTime = maxTime;
                finalAns = ans;
            }
        }
        else {
            minPlanning(k+1, bestTime, bestTime, jobs, machines, ans, finalAns);
        }

        machines[i] -= jobTime;
        ans.pop_back();
    }
}

int main(){
    int n, m; //n = jobs num, m = machines num
    cin >> n >> m;
    vector<int> jobs;
    vector<int> machines (m, 0);
    int time;
    int sumTime = 0;
    for (int i = 0; i < n; i++){
        cin >> time;
        sumTime += time;
        jobs.push_back(time);
    }
    vector<int> finalAns;
    vector<int> ans;

    int bestTime = sumTime;
    minPlanning(0, bestTime, sumTime, jobs, machines, ans, finalAns);
    print_(finalAns);
    // cout << m << ":" << machines.size() << ", " << n << ":" << jobs.size() << endl;
    // cout << countTime(jobs, finalAns, m) << " : " << countTime(jobs, optimal, m) << endl;
}