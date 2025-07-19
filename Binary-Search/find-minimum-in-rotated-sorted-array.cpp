// Binary Search: Find Minimum in Rotated Sorted Array
// Leetcode Problem: 153
//Difficulty: Medium
// Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/1697041419/
// Problem Statement: Given the sorted rotated array nums of unique elements, return the minimum element of this array.


// Approach: Using Binary Search
// 1. Initialize two pointers, left and right, to the beginning and end of the array, respectively.
// 2. While left is less than right, calculate the middle index.
// 3. If the middle element is greater than the rightmost element, it means the minimum is in the right half, so move the left pointer to mid + 1. Because the array is rotated, the minimum element will always be in the unsorted part.
// 4. If the middle element is less than or equal to the rightmost element, it means the minimum is in the left half or it could be the middle element itself, so move the right pointer to mid.
// 5. When left equals right, the minimum element is found at that index.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<r)
        {
            int m = l + (r-l)/2;
            if(nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        return nums[l];
    }
};
// Time Complexity: O(log n), where n is the number of elements in the array.
// Space Complexity: O(1), as we are using a constant amount of space for the
