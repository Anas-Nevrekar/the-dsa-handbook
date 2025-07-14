// Arrays: Max Consecutive Ones 
// Leetcode Problem: 485
//Difficulty: Easy
// Problem Link: https://leetcode.com/problems/max-consecutive-ones/description/
// Problem Statement: Given a binary array nums, return the maximum number of consecutive 1's in the array.

//Approach: We can iterate through the array and keep a count of consecutive 1's. Whenever we encounter a 0, we reset the count to 0. We also keep track of the maximum count encountered so far.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int count = 0;
        int n = nums.size();
        for(int i = 0; i<n;  i++){
            if(nums[i] == 1){ 
                count++;
                max_count = max(max_count, count);
                }
            else count = 0;
        }
        return max_count;
    }
};

//Time Complexity: O(n), where n is the number of elements in the array, since we traverse the array once.
//Space Complexity: O(1), since we are using a constant amount of extra space for the count and max_count variables.