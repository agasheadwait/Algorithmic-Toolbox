#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>

long long int MaxPairwiseProduct(const std::vector<long long int>& numbers) {
    long long int max_product = 0;
    long long int n = numbers.size();
    long long int max1,max2,index;
    max1 = LLONG_MIN;
    max2=LLONG_MIN;


    for (long long int first = 0; first < n; ++first) {
        if(numbers[first]>max1){
            max1=numbers[first];
            index=first;
        }
    }
    for (long long int first = 0; first < n; ++first) {
        if((numbers[first]>max2)&&(index!=first)){
            max2=numbers[first];
        }
    }
    max_product = max1*max2;

    return max_product;
}

int main() {
    long long int n;
    std::cin >> n;
    std::vector<long long int> numbers(n);
    for (long long int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
