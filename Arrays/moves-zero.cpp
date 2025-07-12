// Arrays: Move Zeroes
// Leetcode Problem: 283
//Difficulty: Easy
// Problem Link: https://leetcode.com/problems/move-zeroes/description/
// Problem Statement: Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements. Note that you must do this in-place without making a copy of the array.

//Approach: We can use a two-pointer technique to solve this problem. One pointer (`l`) will track the position of the last non-zero element, and the other pointer (`r`) will iterate through the array. Whenever we encounter a non-zero element, we swap it with the element at the `l` pointer and increment `l`. This way, all non-zero elements are moved to the front of the array, and all zeroes are pushed to the end.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        for(int r=1; r<n; r++)
        {
            if(n == 1) break;
            if(nums[l] != 0 ) l++;
            else if(nums[l]==0 && nums[r]!=0){
                swap(nums[l], nums[r]);
                l++;
            }
        }
    }
};

//Time Complexity: O(n), where n is the number of elements in the array, since we traverse the array once.
//Space Complexity: O(1), since we are modifying the array in-place and not using any extra space.