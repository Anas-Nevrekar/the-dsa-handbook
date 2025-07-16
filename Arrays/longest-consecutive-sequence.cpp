// Arrays: Longest Consecutive Sequence
// Leetcode Problem: 128
//Difficulty: Medium
// Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/description/
// Problem Statement: Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

//Optimal Approach: We can use a hash set to store the elements of the array. For each element, we check if it is the start of a sequence (i.e., the previous element is not in the set). If it is, we count how many consecutive elements exist starting from that element. This way, we ensure that each element is processed only once.


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> n; // Using a hash set to store the elements for O(1) average time complexity for lookups
        for(int i: nums) n.insert(i);
        int max_count = 0;    
        for(int i: nums)
        {   

            int cur_val = i;
            int count = 0;  
            if(n.find(i)!= n.end() && n.find(i-1) == n.end()) // Check if i is the start of a sequence. 
                // If the previous element is not in the set, then i is the start of a sequence.
            {
                while(n.find(cur_val) != n.end()){ // While the current value exists in the set
                    n.erase(cur_val); // Remove it from the set to avoid counting it again
                    count++;
                    cur_val++;
                }
                max_count = max(max_count, count);
            }
        }
        return max_count;
    }
};

//Time Complexity: O(n), where n is the number of elements in the array. 
//Space Complexity: O(n), for storing the elements in the hash set.

//Brute Approach: We can also solve this problem using sorting. We sort the array and then iterate through it to find the longest consecutive sequence. However, this approach has a higher time complexity due to the sorting step.
// Time Complexity: O(n log n) due to sorting, and Space Complexity: O(1) if we sort in place.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int c=1, ans=1;
        for(int i =0; i< nums.size()-1; i++){
            if(nums[i]  ==nums[i+1] -  1) c++;
            else if(nums[i]!=nums[i+1]) c = 1;
            ans = max(ans, c);
        }
        return ans;
    }
};