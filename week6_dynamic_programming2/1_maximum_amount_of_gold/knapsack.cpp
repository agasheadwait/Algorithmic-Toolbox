#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::max;

int optimal_weight(int W, const vector<int> &w)
{
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i)
  {
    if (current_weight + w[i] <= W)
    {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int optimal_weight_dp(int W, const vector<int> &weights)
{
vector<vector<int>> value(weights.size() + 1, vector<int>(W + 1, 0));  for (int i = 1; i <= weights.size(); i++)
  {
    for (int w = 1; w <= W; w++)
    {
      value[i][w] = value[i - 1][w];
      if (weights[i - 1] <= w)
      {
        int val = value[i-1][w - weights[i-1]] + weights[i-1];
        value[i][w] = max(val,value[i][w]);
      }
    }
  }
  return value[weights.size()][W];
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight_dp(W, w) << '\n';
}
