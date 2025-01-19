#include<bits/stdc++.h>

using namespace std;

long long dp(long long n,vector<pair<pair<long long,long long>,long long>> a) {
    vector<long long> dp(n, 0);
    dp[0] = a[0].second;
    for (long long i = 1;i<n;i++) {
        long long prev = 0;
        long long low = 0, high = i-1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (a[mid].first.second < a[i].first.first) {
                prev = dp[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        dp[i] = max(dp[i-1], prev + a[i].second);
    }
    return dp[n-1];
}

bool cmp(pair<pair<long long,long long>,long long> a, pair<pair<long long,long long>,long long> b) {
    return a.first.second < b.first.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<pair<long long,long long>,long long>> a(n, {{0,0},0});
    for(long long i=0;i<n;i++){
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    }
    sort(a.begin(),a.end(), cmp);
    cout << dp(n,a);
}