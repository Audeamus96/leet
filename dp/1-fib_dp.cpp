#include "..\utils\catch.hpp"

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
    if(num == 1)
        return 1;
    
    int result;
    int n1 = 1;
    int n2 = 0;
    for(int i=1; i < num; i++){
        result = n1 + n2;
        n2 = n1;
        n1 = result;
    }

    return result;
}

TEST_CASE("Fib 0 or 1") {
    REQUIRE(fib(0) == 0);
    REQUIRE(fib(1) == 1);
}

TEST_CASE("Fib n") {
    REQUIRE(fib(2) == 1);
    REQUIRE(fib(3) == 2);
    REQUIRE(fib(4) == 3);
    REQUIRE(fib(14) == 377);
}