#include "headers\dp_stairs.hpp"
#include <iostream>
#include <vector>

// Leetcode question 70:
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Naive Approach, recurse downwards
// O(SCARY)
int climbStairs_Naive(int n){
    if(n == 0)  // Base case
        return 1;
    int ans = 0;
    
    if(n > 1)
        ans += climbStairs_Naive(n - 2);
    ans += climbStairs_Naive(n-1);

    return ans;
}

// DP approach, bottom up and store previous values
// TIME: O(N) | SPACE O(N)
int climbStairs(int n){
    std::vector<int> steps(n+1,0);
    steps[0] = 1;

    for(int i=1; i<=n; i++){
        if(i > 1)
            steps[i] += steps[i-2];
        steps[i] += steps[i-1];
    }
    return steps[n];
}

// This is litterally just fibonnacci, no need to store all previous results
// TIME: O(N) | SPACE O(1)
int climbStairs_improved(int n){
    if(n == 1 || n == 0)
        return 1;
    
    int n1 = 1;
    int n2 = 1;
    for(int i=1; i<n; i++){
        int temp = n2;
        n2 = n2 + n1;
        n1 = temp;
    }

    return n2;
}
