#include<iostream>
#include<vector>

using namespace std;

void print_(vector<int> res){
    for (auto iter:res)
        cout << iter << " ";
    cout << "\n";
}

void hoanvi(int n, int k, vector<int> mark, vector<int> res) // tai buoc giai thu k (Sk)
{
    for (int i = 0; i < n; i++){            // lap qua tat ca cac gia tri cua Sk
        if (mark[i] == 0){                  // neu loi giai i la phu hop (chua duoc chon)
            res.push_back(i+1);            // ghi nhan ket qua i  
            mark[i] = 1;                    // cap nhat trang thai

            if (k == n)                     // neu k la buoc giai cuoi cung, xuat kq
                print_(res);
            else                            //nguoc lai hoanvi(k+1) 
                hoanvi(n, k + 1, mark, res);

            mark[i] = 0;                    // tra lai trang thai cu 
            res.pop_back();
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> mark(n, 0);
    vector<int> res;

    hoanvi(n, 1, mark, res);
}