// Binary Search: Koko Eating Bananas
// Leetcode Problem: 875
//Difficulty: Medium
// Problem Link: https://leetcode.com/problems/koko-eating-bananas/submissions/1697041419/
// Problem Statement: Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours. Koko can decide her eating speed k (in bananas per hour), and can eat any amount of bananas in an hour. Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return. Return the minimum integer k such that she can eat all the bananas within h hours.

// Approach: Using Binary Search
// 1. Initialize two pointers, left and right, where left is 1 (minimum speed) and right is the maximum number of bananas in any pile.
// 2. While left is less than or equal to right, calculate the middle speed k.
// 3. Calculate the total hours needed to eat all bananas at speed k.
// 4. If the total hours needed is less than or equal to h, update the answer and try a smaller speed by moving right to mid - 1.
// 5. If the total hours needed is greater than h, increase the speed by moving left to mid + 1.
// 6. Return the minimum speed k that allows Koko to finish eating all bananas within h hours.
class Solution {
    long long total_hours(vector<int>& piles, int k) {
        long long hours = 0;
        for (auto n : piles) {
            hours += (n + k - 1) / k;  // ceil(n / k)
        }
        return hours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long max_pile = *max_element(piles.begin(), piles.end());

        long long l = 1, r = max_pile;
        long long answer = max_pile;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long hours_needed = total_hours(piles, mid);

            if (hours_needed <= h) {
                answer = mid;       // try a smaller k
                r = mid - 1;
            } else {
                l = mid + 1;        // need more speed
            }
        }
        return answer;
    }
};
// Time Complexity: O(n log m), where n is the number of piles and m is the maximum number of bananas in any pile.
// Space Complexity: O(1), as we are using a constant amount of space for the search.
// Note: The total_hours function calculates the total hours needed to eat all bananas at a given
