/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int f[n];
        f[0]=nums[0];
        int ans=f[0];
        for(int i=1;i<n;i++){
            f[i]=nums[i];
            f[i]=max(f[i],f[i-1]+nums[i]);
            ans=max(ans,f[i]);
        }
        return ans;
    }
};
// @lc code=end

