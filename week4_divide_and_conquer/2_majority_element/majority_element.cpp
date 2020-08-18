#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;


int get_majority_element(vector<int> &a, int left, int right) {
  int count=;
  for(int i=0;i<a.size()-1;i++){
    if(a[i]==a[i+1]){
      count++;
      if(count>(a.size()/2)){
        return 1;
      }
    }
    else{
      count=0;
    }
  }
  

  
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  sort(a.begin(),a.end());
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
