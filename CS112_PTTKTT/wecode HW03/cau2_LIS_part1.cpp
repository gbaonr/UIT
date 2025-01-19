#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> computeLIS(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return {};

    vector<int> lis(n, 1); // LIS tại mỗi phần tử
    vector<int> sequence;  // Lưu dãy con tăng dần tạm thời

    for (int i = 0; i < n; ++i)
    {
        int value = arr[i];
        auto pos = lower_bound(sequence.begin(), sequence.end(), value);

        // Nếu phần tử mới lớn hơn tất cả phần tử trước đó -> chèn vào cuối dãy con
        if (pos == sequence.end())
        {
            sequence.push_back(value);
            lis[i] = sequence.size();
        }
        else
        {
            *pos = value;
            lis[i] = distance(sequence.begin(), pos) + 1;
        }
    }

    return lis;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<int> lis = computeLIS(arr);

    // In ra độ dài LIS tại mỗi phần tử
    for (int length : lis)
    {
        cout << length << " ";
    }
    cout << endl;

    return 0;
}
