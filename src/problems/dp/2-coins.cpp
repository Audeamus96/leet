#include "..\..\catch.hpp"
#include <vector>
#include <algorithm>

// Problem: Given a set of coin values coins={c1,c2,...,ck} and a target m, what is the minumum number of coins that form the sum m?


// Naive approach
// Returns -1 if no solution is found
int min_coins_naive(int target, std::vector<int> coins){
    if(target == 0)
        return 0;
    
    int anwser = -1;
    for(int coin : coins){
        int subproblem = target - coin;
        if(subproblem < 0)
            continue; // ignore subproblems with negatives
        anwser = std::min(
                        anwser,
                        min_coins_naive(subproblem, coins) + 1);
    }

    return anwser;

}

TEST_CASE("Fib 0 or 1") {
    REQUIRE(min_coins_naive(0, {1, 2, 5}) == 0);
}
