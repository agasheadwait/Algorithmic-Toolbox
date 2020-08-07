#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
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


long long get_fibonacci_huge_naive(long long n) {
    
    long long prev=0,curr=1;
    if (n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    long long rem = n%60;
    for(long long i=2;i<rem+3;i++){
        long long f = (prev+curr)%60;
        prev=curr;
        curr=f;

        
    }
    return (curr-1)%10;


}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << get_fibonacci_huge_naive(n);
}
