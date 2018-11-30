#include <iostream>

int memo[10] = {0};

int fibonacci(int n){
   
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(memo[n] != 0) return memo[n];

    memo[n] = fibonacci(n-1) + fibonacci(n-2);

    return memo[n];
}

int main(){
    std::cout<<fibonacci(10)<<std::endl;
}