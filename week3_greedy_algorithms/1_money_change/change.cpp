#include <iostream>
#include<cmath>

int get_change(int m) {
  int n=0;
  n+=floor(m/10);
  m = m%10;
  n+=floor(m/5);
  m = m%5;
  return n+m;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
