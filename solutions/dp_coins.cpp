#include "headers\dp_coins.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

// Problem: Given a set of coin values coins={c1,c2,...,ck} and a target m, what is the minumum number of coins that form the sum m?

// helper function
int min_ignore_negative(int a, int b){
    if( a < 0)
        return b;
    if(b < 0)
        return a;
    return std::min(a, b);
}

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
        anwser = min_ignore_negative(
                        anwser,
                        min_coins_naive(subproblem, coins) + 1);
    }

    return anwser;
}

// Bottom-up + memoization approach. O(T*C) where T is the target sum and C the number of coins
int min_coins_memoized(int target, std::vector<int> coins){
    if(target == 0)
        return 0;

    std::vector<int> memo (target);
    memo[0] = 0;
    for(int i = 1; i <= target; i++){
        int anwser = -1;
        for(int coin : coins){
            int subproblem = i - coin;
            if(subproblem < 0)
                continue;  // ignore subproblems with negatives
            anwser = min_ignore_negative(anwser, memo[subproblem]+1);
        }
        memo[i]=anwser;
    }
    return memo[target-1];
}
