#include "headers\dp_fib.hpp"
#include <vector>

int fib(int num){
    std::vector<int> memo (num);
    int result;
    for(int i=1; i<num+1; i++){
        if(i == 1)
            result = 1;
        else   
            result = memo[i-1] + memo[i-2];
        memo[i] = result;
    }
    return result;
}

// Bottom up - more space efficent memoization but worse looking code
int fib2(int num){
    if(num == 0)
        return 0;
    
    int n1 = 1;
    int n2 = 0;
    for(int i=1; i < num; i++){
        int result = n1 + n2;
        n2 = n1;
        n1 = result;
    }

    return n1;
}