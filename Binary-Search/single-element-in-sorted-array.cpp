// Binary Search: Single Element in Sorted Array
// Leetcode Problem: 540
//Difficulty: Medium
// Problem Link: https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/1697041419/
// Problem Statement: Given a sorted array consisting of only integers where every element appears exactly twice except for one element which appears exactly once, return the single element that appears only once.

//Approach: Using Binary Search
// 1. Initialize two pointers, left and right, to the beginning and end of the array, respectively.
// 2. While left is less than right, calculate the middle index.
// 3. If the middle element is not equal to its neighbors, it is the single element, so return it.
// 4. If the middle element is equal to the previous element, check if the index is even or odd.
//    - If it is even, move the right pointer to mid - 2 (because the single element must be on the left side).
//    - If it is odd, move the left pointer to mid + 1 (because the single element must be on the right side). 
// 5. If the middle element is equal to the next element, check if the index is even or odd.
//    - If it is even, move the left pointer to mid + 2 (because the single element must be on the right side).
//    - If it is odd, move the right pointer to mid - 1 (because the single element must be on the left side).

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        if(n == 1) return nums[0];
        if( nums[l] != nums[l+1]) return nums[l];
        if( nums[r] != nums[r-1]) return nums[r];
        while(l<=r)
        {
            int m = r + (l-r)/2;
            if(nums[m] != nums[m-1] && nums[m] != nums[m+1]) return nums[m];
            //2nd position and even -> left
            if(nums[m] == nums[m-1])
            {
                if(m % 2 == 0) r = m - 2;
                else l = m + 1;
            }
            //1st position and even -> right
            else if(nums[m] == nums[m+1])
            {
                if(m%2 == 0) l = m + 2;
                else r = m - 1;
            }
        }
        return -1;
    }
};
//Time Complexity: O(log n), where n is the number of elements in the array.
//Space Complexity: O(1), as we are using a constant amount of space for the search.