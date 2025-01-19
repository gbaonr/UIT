#include <bits/stdc++.h>
using namespace std;

void find(int startIndex, string s, vector<bool>& res) {
    for (int i = startIndex; i < s.size(); ++i) {
        if (i == s.size() - 1) {

        } else {

            for (int j = 0; j <= 1; ++j) {
                res[i] = j;
            }  
        }
    }
}

int main() {
    string s; cin >> s;
}