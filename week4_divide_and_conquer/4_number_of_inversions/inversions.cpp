#include <iostream>
#include <vector>

using std::vector;

int get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
