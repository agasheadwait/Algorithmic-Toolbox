#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

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

long long fib_fast(long long m, long long n){
    return (get_fibonacci_huge_naive(n+2,10)+10 -get_fibonacci_huge_naive(m+1,10))%10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fib_fast(from, to) << '\n';
}
