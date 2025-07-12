// Arrays: Rotated Sorted Array
// Leetcode Problem: 1752
//Difficulty: Easy
// Problem Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
// Problem Statement: Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

//Approach Explanation: Suppose we need to check if this array: [3, 4, 5, 1, 2] is sorted and rotated. We can iterate through the array and check if each element is less than or equal to the next element. If we find an element that is greater than the next one, we reset our count to 1. If we reach a point where our count equals the size of the array, it means the array was originally sorted and then rotated.
//  [3, 4, 5, 1, 2, 3, 4, 5, 1, 2] we will concatenate the array with itself to handle the rotation. This way, we can check for the sorted condition in a circular manner without needing to actually rotate the array.
// it's kind of sliding window approach where we check the sorted condition in a circular manner by iterating through the concatenated array.

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 1;

        for(int i = 0; i < (n-1)*2; i++){ 
            if(nums[i%n]<=nums[(i+1)%n]) {
                count++;
            }
            else count = 1;

            if(count == n) return true;
            
        }
        return (n == 1);
    }
};


//Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) since we are using constant space for the count variable.