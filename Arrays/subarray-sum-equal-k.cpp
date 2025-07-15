// Arrays: Subarray Sum Equal K
// Leetcode Problem: 560
//Difficulty: Medium
// Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/description/
// Problem Statement: Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
//A subarray is a contiguous non-empty sequence of elements within an array.

//Approach: Since we need to find the number of subarrays whose sum equals k, we can use a hash map to store the cumulative sum and its frequency. As we iterate through the array, we can check if the cumulative sum minus k exists in the hash map. If it does, it means there are subarrays that sum to k.
//If the cumulative sum itself equals k, we increment our count. We also update the hash map with the current cumulative sum.

//Optimal Approach
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, c =0;
        unordered_map<int, int> m;

        for(int i =0; i<nums.size(); i++){
            sum += nums[i]; // Calculate the cumulative sum up to the current index.

            if(sum == k) c++; // If the cumulative sum itself equals k, we increment our count.

            if(m.find(sum-k) != m.end()) c += m[sum-k]; // If the cumulative sum minus k exists in the map, it means there are subarrays that sum to k.

            m[sum]++; // Update the map with the current cumulative sum.
        }
        return c;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

//Brute Force Approach
//Approach: We can use a nested loop to check all possible subarrays and their sums. This approach is less efficient but straightforward.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, c= 0;
        for(int i =0; i<nums.size(); i++)
        {
            sum = 0;
           for(int j = i; j<nums.size(); j++)
           {
            sum+=nums[j];
            if(sum == k){
                c++;
            }
           }
        }
        return c;
    }
};
//Time Complexity: O(n^2)
//Space Complexity: O(1)