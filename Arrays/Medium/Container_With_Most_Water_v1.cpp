// 11. Container_With_Most_Water
// Difficulty: Medium

Accepted
65 / 65 testcases passed
Anas_Nevrekar
submitted at Dec 31, 2025 22:33
Solution
2ms
4ms
6ms
0%
25%
50%
75%
2ms
4ms
6ms
Code
C++
1class Solution {
2public:
3    int maxArea(vector<int>& height) {
4          int lp = 0, rp = height.size() - 1;
5        long long maxWater = 0; // Use long long to prevent overflow
6
7        while (lp < rp) {
8            int width = rp - lp;
9            int ht = min(height[lp], height[rp]);
10            long long currWater = (long long)width * ht; // Cast to long long
11            maxWater = max(maxWater, currWater);
12
13            if (height[lp] < height[rp]) {
14                lp++;
15            } else {
16                rp--;
17            }
18        }
19
20        return (int)maxWater;
21    }
22};
View more
 
0/5
