#include <iostream>
#include <vector>

using std::vector;
using std::max;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  int l=a.size(),m=b.size(),n=c.size();
  int L[l+1][m+1][n+1]={0};
  for(int i=0;i<=l;i++){
    for(int j=0;j<=m;j++){
      for(int k=0;k<=n;k++){
        if(i==0 or j==0 or k==0){
          L[i][j][k]=0;
        }
        else if(a[i-1]==b[j-1] && a[i-1]==c[k-1]){
          L[i][j][k] = L[i-1][j-1][k-1]+1;
        }
        else{
          L[i][j][k] = max(max(L[i][j][k-1],L[i][j-1][k]),L[i-1][j][k]);
        }
      }
    }
  }
  return L[l][m][n];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
