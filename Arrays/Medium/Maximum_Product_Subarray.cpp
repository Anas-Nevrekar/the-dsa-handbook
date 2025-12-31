// 152. Maximum_Product_Subarray
// Difficulty: Medium

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cur_max=1, cur_min =1;
        int ans = INT_MIN;
        for(int n:nums) ans = max(ans, n);
        for(int i =0; i<nums.size(); i++)
        {
            int n = nums[i];
            if(n==0)
            {
                cur_min =1;
                cur_max = 1;
                continue;
            }
           int temp1 = n*cur_max;
            int temp2 = n*cur_min;
            cur_max = max(n,max(n*cur_max, n*cur_min));
            cur_min = min(n, min(temp1, temp2));
            ans = max(ans, cur_max);
        }
        
        return ans; 
    }
};
