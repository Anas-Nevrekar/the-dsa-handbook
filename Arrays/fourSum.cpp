// Arrays: Four Sum
// Leetcode Problem: 18
//Difficulty: Medium
// Problem Link: https://leetcode.com/problems/4sum/description/
// Problem Statement: Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

//Approach: We can solve this problem using a two-pointer technique after sorting the array. The idea is to fix two numbers and then use two pointers to find the other two numbers that sum up to the target minus the sum of the fixed numbers. We also need to ensure that we skip duplicates to avoid counting the same quadruplet multiple times.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort the array to use two-pointer technique and to easily skip duplicates

        for(int i = 0; i<n; i++) // Fix the first number
        {
            if(i>0 && nums[i] == nums[i-1]) continue; // Skip duplicates for the first number
            for(int j = i+1; j<n;) // Fix the second number
            {
                int l = j+1, r = n-1;
                while(l<r)
                {
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];  
                    if(sum>target) r--;
                    else if(sum<target) l++;
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        while(l<r && nums[l]==nums[l-1]) l++;
                        while(l<r && nums[r] == nums[r+1]) r--;
                    }
                }
               j++;
               while(j<n && nums[j]==nums[j-1]) j++; // Skip duplicates for the second number
            }
        }
        return ans;
    }
};

// Time Complexity: O(n^3) - The outer loop runs in O(n^2) and the two-pointer search runs in O(n).
// Space Complexity: O(1) - We are using a constant amount of extra space for the pointers and indices, not counting the output space.