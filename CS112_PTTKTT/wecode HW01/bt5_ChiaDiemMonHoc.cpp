#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>

using namespace std;

double delta = 1e-5;
int count = 0;

bool check(double a, double score){
    if (abs(a-score) <= delta) 
        return true;
    return false;
}

void print_(vector<double> res){
    for (auto& iter:res){
        printf("%.3g ", iter);
    }
    printf("\n");
    // count += 1;
}

void chiadiem(int k, double score, vector<int> heso, vector<double>& res, double& currentScore ){
    for (double i = 0.25; i <= 10; i+= 0.25)
    {
        res[k-1] = i;
        double add = i*heso[k-1]/100.0;
        currentScore += add;

        double roundScore = floor(currentScore*10 +0.5 + delta)/10.0;
        // cout << roundScore << " - " << score << " k = " << k << endl; 

        if (roundScore <= score){ 
            if (k == heso.size()){
                if(abs(score - roundScore) <= delta) // if roundScore ~ score
                    print_(res);
            }
            else if (k < heso.size()) // chua phai buoc giai cuoi -> de quy
            {
                // cout << "k + 1\n";
                chiadiem(k+1, score, heso, res, currentScore);
            }
            
            // if (buoc giai cuoi) --> tra lai trang thai cu
            currentScore -= add;
        }
        // if (roundScore > score) -> tra lai trang thai cu -> ko duyet tiep nhanh nay
        else {
            currentScore -= add;
            break;      
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(3);

    int n;
    cin >> n;
    vector<int> heso(n);
    for (int i = 0 ; i < n; i++){
        cin >> heso[i];
    }
    
    double score;
    double currentScore = 0;
    cin >> score;
    vector<double> res(n);
    
    chiadiem(1, score, heso, res, currentScore);

    // cout << "-->" << count;

    // double a;
    // cin >> a;
    // cout << check(a, 9.500);

}