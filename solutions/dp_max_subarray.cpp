#include "headers\dp_max_subarray.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

// Leetcode 53: Maximum Subarray
// Given an integer array nums, find the subarray with the largest sum, and return its sum.
// Useful Constraints:
//      1 <= nums.length <= 105


// First Attempt, O(N) solution
int maxSubArray(std::vector<int>& nums){
    if(nums.size() == 1){
        return nums[0];
    }

    int curr_sum = nums[0];
    int max_sum = curr_sum;
    for(int i=1; i < nums.size(); i++){
        // printf("curr_sum: %i\n", curr_sum);
        if(curr_sum < 1 && nums[i] > curr_sum){
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
        }else{
            curr_sum += nums[i];
            if(max_sum < curr_sum)
                max_sum = curr_sum;
        }
    }
    return max_sum;
}

// int main(){
//  std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
//  std::vector<int> nums1 = {5,4,-1,7,8};
//  std::vector<int> nums2 = {1};
//  std::vector<int> nums3 = {-2,-3,-4,-4,-5};
//  std::vector<int> nums4 = {-2,1};
//  printf("ans: %i\n", maxSubArray(nums));
//  printf("ans: %i\n", maxSubArray(nums1));
//  printf("ans: %i\n", maxSubArray(nums2));
//  printf("ans: %i\n", maxSubArray(nums3));
//  printf("ans: %i\n", maxSubArray(nums4));
//  }
