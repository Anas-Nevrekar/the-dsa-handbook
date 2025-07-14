// Arrays: Two Sum
// Leetcode Problem: 1
//Difficulty: Easy
// Problem Link: https://leetcode.com/problems/two-sum/submissions/1697041419/
// Problem Statement: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

//Approach:
// 1. Create a hash map to store the numbers and their indices.
// 2. Iterate through the array, for each number, calculate the difference between the target and the current number.
// 3. Check if this difference exists in the hash map.
// 4. If it exists, return the indices of the current number and the number that makes up the target.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> numMap;

for(int i =0; i< nums.size(); i++){
    int curr_num = nums[i];
    int diff = target- curr_num;
    
    if(numMap.count(diff)){
        return {numMap[diff], i};
    }
    numMap[curr_num]=i;
}
return {};
    }
};

// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n), for storing the elements in the hash map.