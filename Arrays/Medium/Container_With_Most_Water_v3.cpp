// 11. Container_With_Most_Water
// Difficulty: Medium

/ 65 testcases passed
ms
ms
ms
%
%
%
%
ms
ms
ms
class Solution {
public:
    int maxArea(vector<int>& height) {
          int lp = 0, rp = height.size() - 1;
        long long maxWater = 0; // Use long long to prevent overflow

        while (lp < rp) {
            int width = rp - lp;
            int ht = min(height[lp], height[rp]);
            long long currWater = (long long)width * ht; // Cast to long long
            maxWater = max(maxWater, currWater);

            if (height[lp] < height[rp]) {
                lp++;
            } else {
                rp--;
            }
        }

        return (int)maxWater;
    }
};
/5
