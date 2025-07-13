// Arrays: Missing Number
// Leetcode Problem: 268
//Difficulty: Easy
// Problem Link: https://leetcode.com/problems/missing-number/description/
// Problem Statement: Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

//Approach: We can calculate the sum of the first n natural numbers using the formula n*(n+1)/2 (although i did it using loop) and subtract the sum of the elements in the array from it. The difference will give us the missing number.



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++) sum1+=nums[i];
        for(int i = 1; i<=n; i++) sum2+=i;
        return sum2-sum1;
    }
};

//Time Complexity: O(n), where n is the number of elements in the array, since we traverse the array once to calculate the sum.
//Space Complexity: O(1), since we are using a constant amount of extra space for the sum variables.