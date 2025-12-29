// 26. Remove_Duplicates_from_Array
// Difficulty: Hard

#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0, rp = height.size() - 1;
        long long maxWater = 0;

        while (lp < rp) {
            int width = rp - lp;
            int ht = min(height[lp], height[rp]);
            long long currWater = (long long) width * ht;
            maxWater = max(maxWater, currWater);

            if (height[lp] < height[rp]) {
                lp++;
            } else {
                rp--;
            }
        }
        return (int) maxWater;
    }
};
