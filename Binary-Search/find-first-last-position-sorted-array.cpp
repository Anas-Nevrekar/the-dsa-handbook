// LeetCode Problem: Find First and Last Position of Element in Sorted Array
//Problem number: 34
//Problem Difficulty: Medium
//Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//Problem Description: Given an array of integers sorted in ascending order, find the starting and ending position of a given target value. If the target is not found in the array, return [-1, -1]. You must write an algorithm with O(log n) runtime complexity.

//Approach: The solution uses binary search to find the first and last positions of the target value in the sorted array. It performs two separate binary searches: one for the first occurrence and another for the last occurrence of the target.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int st = 0, end = nums.size()-1;
        
        if(nums.size() == 0) return ans;
        if(nums.size() == 1 && nums[0] == target) return {0,0};
        if(nums.size() == 1 && nums[0] != target) return ans;
        
        // Binary search for the last occurrence of the target
        while(st<=end) 
        {   
            if(nums[nums.size()-1] == target) 
            {
                ans[1] = nums.size()-1;
                break;
            }
            int mid = st + (end - st)/2;
            if(nums[mid] == target)
            {
                if (nums[mid] != nums[mid+1])
                {
                    ans[1] = mid;
                    break;
                }
                else  st = mid + 1;

            }
            else if(nums[mid] < target) st = mid + 1;
            else end = mid - 1;
        }
        // Binary search for the first occurrence of the target
          st = 0, end = nums.size()-1;
        while(st<=end)
        {   
            if(nums[0] == target) {
                ans[0] = 0;
                break;
            }
            int mid = st + (end - st)/2;
            if(nums[mid] == target )
            {
                if(nums[mid] != nums[mid-1]){
                ans[0] = mid;
                break;
                }
                else end = mid - 1; 

            }
            else if(nums[mid] < target) st = mid + 1;
            else end = mid - 1;
        }
        return ans;
    }
};

//Time Complexity: O(log n) for each binary search, resulting in a total time complexity of O(log n).
//Space Complexity: O(1) since we are using a constant amount of extra space for the answer vector and variables.