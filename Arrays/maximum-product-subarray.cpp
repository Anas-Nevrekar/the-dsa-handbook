// Arrays: Maximum Product Subarray
// Leetcode Problem: 152
//Difficulty: Medium
// Problem Link: https://leetcode.com/problems/maximum-product-subarray/description/
// Problem Statement: Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

//Optimized Approach: 
//Step 1: Initialize variables to keep track of the current maximum product, current minimum product, and the overall maximum product.
//Step 2: Iterate through the array, updating the current maximum and minimum products based on the current number.
// Step 3: If the current number is zero, reset both current maximum and minimum products to 1.
// Step 4: Update the overall maximum product with the current maximum product.
//Step 5: Return the overall maximum product.

//Note: This solution handles both positive and negative numbers, as well as zeros in the input array. The key is to keep track of both the maximum and minimum products at each step, since a negative number can turn a small product into a large one when multiplied by another negative number.
// This approach ensures that we find the maximum product subarray efficiently without needing to check all possible subarrays.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cur_max=1, cur_min =1;
        int ans = INT_MIN; // Initialize ans to the smallest possible integer
        for(int n:nums) ans = max(ans, n); // Finding the maximum element 
        for(int i =0; i<nums.size(); i++)
        {
            int n = nums[i];
            if(n==0) // If the current number is zero, reset both current max and min products. Because multiplying by zero will reset the product.
            {
                cur_min =1;
                cur_max = 1;
                continue;
            }
           int temp1 = n*cur_max; // Store the product of current number and current max
            int temp2 = n*cur_min; // Store the product of current number and current min
            cur_max = max(n,max(n*cur_max, n*cur_min)); // Update current max product
            cur_min = min(n, min(temp1, temp2)); // Update current min product
            ans = max(ans, cur_max); // Update the overall maximum product
        }
        
        return ans; 
    }
};

//Time Complexity: O(n), where n is the number of elements in the input array.
//Space Complexity: O(1), as we are using a constant amount of space for variables.


//Burte Force Approach:
// This approach checks all possible subarrays and calculates their products to find the maximum product.
// However, it is not efficient for large arrays due to its O(n^2) time complexity.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_ans=INT_MIN;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 0) return 0;
        for(int i =0; i<nums.size(); i++)
        {
            int ans = nums[i];
            for(int j = i+1; j<nums.size(); j++)
            {
               max_ans = max(max_ans, ans);
                ans*= nums[j];
                
                
            }
            max_ans = max(max_ans, ans);

        }
        return max_ans;
    }
};
//Time Complexity: O(n^2), where n is the number of elements in the input array.
//Space Complexity: O(1), as we are using a constant amount of space for variables.
