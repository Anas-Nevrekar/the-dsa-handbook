// 88. Merge_Sorted_Array
// Difficulty: Easy

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n;
        while(k>0){
            if (n == 0){
                k--;
            }
            else if (m == 0){
                nums1[k-1]=nums2[n-1];
                k--;
                n--;
            }
            else {
                if(nums1[m-1]>=nums2[n-1]){
                    nums1[k-1] = nums1[m-1];
                    k--;
                    m--;
                }
                else{
                    nums1[k-1]=nums2[n-1];
                    k--;
                    n--;
                }
            }
        }
    }
};
