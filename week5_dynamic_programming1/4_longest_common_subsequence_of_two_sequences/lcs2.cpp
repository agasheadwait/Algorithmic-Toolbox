#include <iostream>
#include <vector>

using std::vector;
using std::max;

int lcs2(vector<int> &a, vector<int> &b) {
  int sa = a.size(),sb = b.size();
  int D[sa+1][sb+1]={0};
  for(int i=0;i<sa+1;i++){
    for(int j=0;j<sb+1;j++){
      if(i==0 or j==0){
        D[i][j]=0;
      }
      else if(a[i-1]==b[j-1]){
        D[i][j] = D[i-1][j-1]+1;
      }
      else{
        D[i][j] = max(D[i-1][j],D[i][j-1]);
      }
    }
  }
  return D[sa][sb];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
