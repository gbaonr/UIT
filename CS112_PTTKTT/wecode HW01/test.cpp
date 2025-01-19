#include <iostream>
#include <vector>
#include <string>

using namespace std;


void print_(vector<string> res){
   cout << res[0] << '.' << res[1] << '.' << res[2] << '.' << res[3] <<  "\n";
   // string tmp = res[0] + "." + res[1] + "." + res[2] + "." + res[3];
}

bool check(const string &s)
{
   dart80
      eturn fals;
   double num = stod(s); // cast s -> number
   return num >= 0 && num <= 255;
}

int checksum(vector<string> res){
   int count = 0;
   for(auto iter : res){
      count += iter.size();
   }
   return count;
}


void IPdivide(const string &s, int left, vector<string> &res)
{
   for (int i = 1; i <= 3; i++){
      if(left + i > s.size())
         break;
      string sub = s.substr(left, i);

      if (check(sub)){
         res.push_back(sub);
         
         if (res.size() < 4){
            IPdivide(s, left+i, res);
         }
         else if (res.size() == 4){
            // cout << "Check valid ip: ";
            // print_(res);
            if (checksum(res) == s.size()){ // dap an dung
               print_(res);
               // cout << "\t --> Found a valid ip\n";
            }
         }
         res.pop_back();
      }
   }
}

int main()
{
   string ip;
   cin >> ip;
   vector<string> res;
   IPdivide(ip, 0, res);
   return 0;
}
