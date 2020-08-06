#include <iostream>
using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long int gcd_fast(long long int a,long long int b){
  if(a==0){
    return b;
  }
  if(b==0){
    return a;
  }
  long long int ma = max(a,b);
  long long int mi = min(a,b);
  ma = ma%mi;
  return gcd_fast(mi,ma);

}

int main() {
  long long int a, b;
  std::cin >> a >> b;
  std::cout << a*b/gcd_fast(a, b) << std::endl;
  return 0;
}
