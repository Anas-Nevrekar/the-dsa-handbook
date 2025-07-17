// Arrays: 3sum
// Leetcode Problem: 15
//Difficulty: Medium
// Problem Link: https://leetcode.com/problems/3sum/description/
// Problem Statement: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0. Notice that the solution set must not contain duplicate triplets.

//Approach: 
// 1. Sort the input array to facilitate duplicate handling and two-pointer technique.
// 2. Iterate through the array, treating each element as a potential first element of the triplet.
// 3. For each element, use two pointers (left and right) to find pairs
//    that, together with the current element, sum to zero.
// 4. Skip duplicates to ensure unique triplets are added to the result.
// 5. Return the list of unique triplets that sum to zero.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array to handle duplicates and use two pointers
         vector<vector<int>> ans;
            for(int i=0; i<nums.size(); i++)
            {   
                if(i>0 && nums[i] == nums[i-1]) continue; // Skip duplicates for the first element

                int l = i+1;
                int r = nums.size()-1;
                while(l<r)
                {
                    int sum = nums[i] + nums[l] + nums[r];
                    if(sum > 0) r--; // If the sum is greater than zero, move the right pointer left
                    else if (sum < 0) l++; // If the sum is less than zero, move the left pointer right
                    else {
                         ans.push_back({nums[i], nums[l], nums[r]}); 
                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l-1]) l++; // Skip duplicates from left pointer
                        while(l < r && nums[r] == nums[r+1]) r--; // Skip duplicates from right pointer
                    }

                }
            }
            return ans;
    }
};


// Time Complexity: O(n^2), where n is the number of elements in the input array.
// Space Complexity: O(1) for the two-pointer approach
