#include "headers\dp_max_subarray.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

#define isLessThanOne(x) (x < 1)

// Leetcode 53: Maximum Subarray (https://leetcode.com/problems/maximum-subarray/)
// Given an integer array nums, find the subarray with the largest sum, and return its sum.
// Useful Constraints:
//      1 <= nums.length <= 10^5
//      -10^4 <= nums[i] <= 10^4


// First Attempt, O(N) solution
// This is not a dp solution and clearly really gross looking
int maxSubArray_non_dp(std::vector<int>& nums){
    if(nums.size() == 1){
        return nums[0];
    }

    int curr_sum = nums[0];
    int max_sum = curr_sum;
    for(int i=1; i < nums.size(); i++){
        // if curr_sum is less than one and nums[i] is greater, then replace curr_sum
        if(isLessThanOne(curr_sum) && nums[i] > curr_sum){
            curr_sum = nums[i];
            if(max_sum < curr_sum)
                max_sum = curr_sum;
            continue;
        }
        
        // if the nums[i] decreases curr_sum by more than curr_sum
        if(std::abs(curr_sum) + nums[i] <= 0){
            if(max_sum < curr_sum)
                max_sum = curr_sum;
            curr_sum = nums[i];
        // otherwise add nums[i] to curr_sum
        }else{
            curr_sum += nums[i];
            if(max_sum < curr_sum)
                max_sum = curr_sum;
        }
    }
    return max_sum;
}

// To work towards a dp solution we first need to break it into subproblems
// My idea is to break it into the sub-problem maxSubArray(A[], i) where i is the start index of the array (i < A[].length).

int maxSubArray(std::vector<int>& nums){
    if(nums.size() == 1)
        return nums[0];
    
    int max = nums[0], running_sum = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(running_sum < 0)
            // if the running sum is negative, adding nums[i] to it will only make it smaller, set it to nums[i] instead
            running_sum = nums[i]; 
        else
            // the running sum is positive, add nums[i] to it and compare that to the golbal max
            running_sum = running_sum+nums[i];
        max = std::max(running_sum, max);
    }
    
    return max;
}
