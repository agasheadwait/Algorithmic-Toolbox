#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition3(vector<int> &A)
{
  if (accumulate(A.begin(), A.end(), 0) % 3 == 0)
  {
    if(A.size()<3){
      return 0;
    }
    
  }
  else
  {
    return 0;
  }
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i)
  {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
