// Binary Search: Search Insert Position
// Leetcode Problem: 35
//Difficulty: Easy
// Problem Link: https://leetcode.com/problems/search-insert-position/submissions/1697041419/
// Problem Statement: Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// Approach: Using Binary Search
// 1. Initialize two pointers, start and end, to the beginning and end of the array, respectively.
// 2. While start is less than or equal to end, calculate the middle index.
// 3. If the middle element is equal to the target, return the middle index.
// 4. If the middle element is greater than the target, move the end pointer to mid - 1.
//5. If the middle element is less than the target, move the start pointer to mid + 1.
// 6. If the target is not found, return the start pointer, which will be the index where the target would be inserted.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0, end = nums.size()-1;
        while(st<=end)
        {
            int mid = st + (end - st) / 2;
            if(nums[mid] == target) return mid;
            if (nums[mid] > target ) end = mid - 1;
            else st = mid+ 1;
        }
        return st;
    }
};
// Time Complexity: O(log n), where n is the number of elements in the array.
// Space Complexity: O(1), as we are using a constant amount of space for the pointers.