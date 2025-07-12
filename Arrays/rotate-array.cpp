// Arrays: Rotate Array
// Leetcode Problem: 189
//Difficulty: Medium
// Problem Link: https://leetcode.com/problems/rotate-array/description/
// Problem Statement: Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(n > 1){
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        }

    }
};

//Approach: Step 1: Reverse the entire array.
//Step 2: Reverse the first k elements.
//Step 3: Reverse the remaining n-k elements.
//Time Complexity: O(n)
//Space Complexity: O(1) - In-place rotation