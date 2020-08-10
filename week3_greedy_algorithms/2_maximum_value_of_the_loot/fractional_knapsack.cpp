#include<bits/stdc++.h> 

using namespace std;

bool comp(pair <double,pair<int,int>>p1,pair <double,pair<int,int>>p2){
  return p1.first>p2.first;
}

double get_optimal_value(double capacity, vector<double> w, vector<double> v) {
  double value = 0.0;
  vector< pair <double,pair<double,double>> > ans;
  for(double i=0;i<w.size();i++){
    ans.push_back(make_pair(v[i]/w[i],make_pair(v[i],w[i])));
  }
  sort(ans.begin(),ans.end(),comp);
  while(capacity>0 && ans.size()>0){
    if(ans[0].second.second<=capacity){
      value+=ans[0].second.first;
      capacity-=ans[0].second.second;
    }
    else
    {
      value+=ans[0].first*capacity; 
      capacity=0;
    }
    ans.erase(ans.begin());
    
  }
  

  return value;
}

int main() {
  double n;
  double capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (double i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
