#include <iostream>
#include<algorithm>
using namespace std;

long long pisano(long long m){
    long long prev=0,curr=1;
    long long temp;
    for(long long i=0;i<m*m;i++){
        temp = prev;
        prev = curr;
        curr =  (temp+curr)%m;
        if(prev==0 && curr==1){
            return i+1;
        }
    }
}


long long get_fibonacci_huge_naive(long long n, long long m) {
    long long pisanop = pisano(m);
    n = n%pisanop;
    long long prev=0,curr=1;
    if (n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    for(long long i=0;i<n-1;i++){
        curr=curr+prev;
        prev = curr-prev;
        curr=curr%m;
        prev=prev%m;
        
    }
    return curr%m;


}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
