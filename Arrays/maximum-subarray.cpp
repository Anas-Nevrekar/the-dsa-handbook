// Arrays: Maximum Subarray 
// Leetcode Problem: 53
//Difficulty: Medium
// Problem Link: https://leetcode.com/problems/maximum-subarray/description/
// Problem Statement: Given an integer array nums, find the subarray with the largest sum, and return its sum. 
//Approach: Kadane's Algorithm
//step 1: Initialize two variables, sum and max_sum. Set sum to 0 and max_sum to the smallest integer value.
//step 2: Iterate through each element in the array.
//step 3: Add the current element to sum.
//step 4: Update max_sum to be the maximum of max_sum and sum.
//step 5: If sum becomes negative, reset it to 0.
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            max_sum = max(max_sum, sum);
            if (sum<0) sum = 0;
        }
        return max_sum;
    }
};

//Time Complexity: O(n) where n is the number of elements in the array.
//Space Complexity: O(1) as we are using only a constant amount of space for variables.