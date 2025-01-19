#include<string>
#include<iostream>
#include<vector>

using namespace std;


void roundBrackets(int k, int& left, int& right, vector<char>& res){
    for (auto i:{'(', ')'}){
        if (left > res.size()/2 || right > left)
            break;

        res[k-1] = i;
        if (i == '(')
            left += 1;
        if (i == ')')
            right += 1;

        if (k == res.size()){
            if (left == right && left == res.size()/2) {
                for (auto iter : res){
                    printf("%c", iter);
                }
                printf("\n");
            }
        }
        else if (k < res.size()){
            roundBrackets(k+1, left, right, res);
        }

        //tra ve trang thai cu
        if (i == '(')
            left -= 1;
        if (i == ')')
            right -= 1;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<char> res(2*n);

    int left = 0;
    int right = 0;
    
    roundBrackets(1, left, right, res);
}