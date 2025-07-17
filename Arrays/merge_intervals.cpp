// Arrays: Merge Intervals
// Leetcode Problem: 56
//Difficulty: Medium
// Problem Link: https://leetcode.com/problems/merge-intervals/description/
// Problem Statement: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

//Approach: 
// 1. Sort the intervals based on the starting time.
// 2. Initialize an empty vector to store the merged intervals.
// 3. Iterate through the sorted intervals:
//    - If the current interval does not overlap with the last merged interval, add it to the result.
//    - If it overlaps, merge it by updating the end time of the last merged interval.
// 4. Return the merged intervals.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for(int i=0; i<n; i++)
        {
            if(ans.empty() || intervals[i][0] > ans.back()[1]){ 
                ans.push_back(intervals[i]);
                continue;
            }
            if(intervals[i][0] <= ans.back()[1])
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }

        } 
        return ans;
    }
};
// Time Complexity: O(n log n), where n is the number of intervals (due to sorting).
// Space Complexity: O(n) for storing the merged intervals.