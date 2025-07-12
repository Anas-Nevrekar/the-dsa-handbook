// Arrays: Remove Duplicates from Sorted Array
// Leetcode Problem: 26
//Difficulty: Easy
// Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description
// Problem Statement: Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 1;
   
   for(int r = 1; r < nums.size(); r++){
       if (nums[r]!=nums[r-1]){
        nums[l] = nums[r];
        l++;
       }
    }
    return l;
    }
};

//Approach: Since the array is sorted, we can use two pointers to keep track of the unique elements. The first pointer `l` will point to the position where the next unique element should be placed, and the second pointer `r` will iterate through the array. Whenever we find a new unique element (i.e., `nums[r] != nums[r-1]`), we place it at the position pointed by `l` and increment `l`. Finally, we return `l`, which represents the number of unique elements in the array.
//Time Complexity: O(n), where n is the number of elements in the array.
//Space Complexity: O(1), since we are modifying the array in-place and not using any extra space.

//Brute Force Approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
   
   for(int i = 1; i < nums.size(); i++){
       if (nums[i]==nums[i-1]){
       nums.erase(nums.begin()+ i);
       i--;
       }
       else {
           count++;
       }
    }
    return count;
    }
};
//Approach: This brute force approach uses the `erase` method to remove duplicates from the vector. It iterates through the array and checks if the current element is equal to the previous one. If they are equal, it removes the current element and decrements the index to account for the shift in elements. The count of unique elements is maintained.
//Time Complexity: O(n^2), where n is the number of elements in the array, due to the repeated calls to `erase` which can take O(n) time.
//Space Complexity: O(1), since we are modifying the array in-place and not using any extra space.