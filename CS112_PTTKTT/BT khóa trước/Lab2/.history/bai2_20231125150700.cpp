#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// cur - index res dang xet
void find()
{
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;

    while (n) {
        nums.push_back(n % 10);
        n /= 10;
    }

    sort(nums.begin(), nums.end(), greater<int>());

    vector<int> ans(nums.size(), 0);
}