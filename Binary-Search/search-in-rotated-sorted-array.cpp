// Arrays: Search in Rotated Sorted Array
// Leetcode Problem: 33
// Difficulty: Medium
// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// Problem Statement: Given an integer array nums sorted in ascending order, and an integer target, write a function to search for target in nums. If target exists, then return its index. Otherwise, return -1. You must write an algorithm with O(log n) runtime complexity.

// Approach:
// 1. Use binary search to find the target in the rotated sorted array. 
// 2. Determine which half of the array is sorted.
// 3. Check if the target is within the bounds of the sorted half.
// 4. Adjust the search range based on whether the target is in the sorted half or the unsorted half.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1, mid;

        // Binary Search Loop: Runs as long as s <= e
        while (s <= e) {
            // Calculate Midpoint
            mid = s + (e - s) / 2;

            // Check for Target
            if (nums[mid] == target)
                return mid;

            // Determine Sorted Half
            if (nums[s] <= nums[mid]) { // Left half is sorted
                // Narrow Down the Search
                if (nums[s] <= target && target <= nums[mid]) // Target lies in the left half
                    e = mid - 1;
                else // Target lies in the right half
                    s = mid + 1;
            } else { // Right half is sorted
                // Narrow Down the Search
                if (nums[mid] <= target && target <= nums[e]) // Target lies in the right half
                    s = mid + 1;
                else // Target lies in the left half
                    e = mid - 1;
            }
        }

        // Return -1: Target not found
        return -1;
    }
};

// Time Complexity: O(log n), where n is the number of elements in the array.
// Space Complexity: O(1), as we are using a constant amount of space for variables


