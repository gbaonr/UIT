#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(const string &s) {
    if (s.size() > 1 && s[0] == '0') // Kiểm tra xem chuỗi số có bắt đầu bằng 0 không (ngoại trừ trường hợp số 0)
        return false;
    int num = stod(s); // Chuyển đổi chuỗi số thành số nguyên
    return num >= 0 && num <= 255;
}

void backtrack(const string &s, int start, vector<string> &current, vector<string> &result) {
    if (start == s.size() && current.size() == 4) { // Nếu đã xử lý xong chuỗi số và đã có 4 phần tử trong địa chỉ IP
        result.push_back(current[0] + '.' + current[1] + '.' + current[2] + '.' + current[3]); // Thêm địa chỉ IP vào kết quả
        return;
    }
    if (current.size() >= 4) // Nếu đã có 4 phần tử trong địa chỉ IP nhưng chuỗi số chưa được xử lý xong
        return;
    for (int i = start; i < s.size(); ++i) { // Lặp qua từng ký tự trong chuỗi số
        string sub = s.substr(start, i - start + 1); // Tạo một phần tử mới từ start đến i
        if (isValid(sub)) { // Kiểm tra xem phần tử này có hợp lệ không
            current.push_back(sub); // Thêm phần tử vào địa chỉ IP tạm thời
            backtrack(s, i + 1, current, result); // Gọi đệ quy để xử lý phần tử tiếp theo
            current.pop_back(); // Loại bỏ phần tử vừa thêm vào để thử các phần tử khác
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    vector<string> current;
    backtrack(s, 0, current, result);
    return result;
}

int main() {
    string s = "25525511135";
    cin >> s;
    vector<string> ips = restoreIpAddresses(s);
    for (const string &ip : ips) {
        cout << ip << endl;
    }
    return 0;
}
