#include "headers\dp_coins_2.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

// Problem: Given a set of coin values coins={c1,c2,...,ck} and a target sum m,
// in how many ways can the sum m be formed?

int num_ways_naive(int sum, std::vector<int> coins){
    if(sum == 0)
        return 1;
    
    int ans = 0;
    for(int coin: coins) {
        int subproblem = sum - coin;
        if(subproblem < 0)          // not valid path to sum
            continue;
        ans += num_ways_naive(subproblem, coins);
    }

    return ans;
}

// bottom up + memoization approach
unsigned long long int num_ways_dp(int m, std::vector<int> coins){
    std::vector<unsigned long long int> num_ways(m+1);
    num_ways[0] = 1;

    for(int i=1; i <= m; i++){
        num_ways[i] = 0;
        for(int coin : coins) {
            int subproblem = i - coin;
            if(subproblem < 0)
                continue;
            num_ways[i] += num_ways[subproblem];
        }
    }

    return num_ways[m];
}

// int main() {
//     printf("ans = %i\n", num_ways_naive(6, {1, 4, 5}));
//     printf("ans = %llu\n", num_ways_dp(87, {1, 4, 5, 8}));
// }
