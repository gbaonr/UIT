#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// cur - index res dang xet
void find(int cur, vector<int>& nums, vector<int>& res, vector<bool>& used)
{
    for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
            used[i] = true;
            res[cur] = nums[i];

            if (cur == nums.size() - 1) {
                for (auto& v : res) {
                    cout << v;
                }
                cout << '\n';
            } else {
                find(cur + 1, nums, res, used);
            }

            used[i] = false;
        }
    }
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

    // sort(nums.begin(), nums.end(), greater<int>());

    // luu ket qua, ans[i] la so duoc chon tai vi tri i
    vector<int> res(nums.size(), 0);

    // neu da su dung nums[i] thi used[i] = true
    vector<bool> used(nums.size(), 0);

    // tim so bat dau tu vi tri 0
    find(0, nums, res, used);
}