#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int arr[1000]={0};

int get_change(int m) {
  int coins[3] = {1,3,4};
  arr[0] = 0;
  int numcoins;
  for(int i=1;i<=m;i++){
    arr[i] = INT_MAX;
    for(int j=0;j<3;j++){
      if(m>=coins[j]){
        numcoins = arr[i-coins[j]]+1;
        arr[i] = min(arr[i],numcoins);
      }
    }
  }
  return arr[m];

}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
