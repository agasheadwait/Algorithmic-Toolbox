#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
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

int fibonacci_sum_squares_fast(long long n){
    return (get_fibonacci_huge_naive(n,10)*get_fibonacci_huge_naive(n+1,10))%10;
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
