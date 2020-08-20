#include <iostream>
#include <algorithm>
#include <string>

using std::string;
using std::min;

int edit_distance(const string &str1, const string &str2) {
  int n = str1.length(),m = str2.length();
  int D[n+1][m+1]={0};
  for(int i=0;i<=n;i++){
    D[i][0] = i;
  }
  for(int i=0;i<=m;i++){
    D[0][i] = i;
  }
  for(int j=1;j<=m;j++){
    for(int i=1;i<=n;i++){
      int ins = D[i][j-1]+1;
      int del = D[i-1][j]+1;
      int mis = D[i-1][j-1]+1;
      int mat = D[i-1][j-1];
      if(str1[i-1]==str2[j-1]){
        D[i][j] = min(min(ins,del),mat);
        // std::cout<<str1[i-1]<<' '<<str2[j-1]<<' '<<'m'<<"\n";
      }
      else{
        D[i][j] = min(min(ins,del),mis);
        // std::cout<<str1[i-1]<<' '<<str2[j-1]<<' '<<'n'<<"\n";
      }
    }
  }
  return D[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
