/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxpos=0,ends=0;
        for(int i=0;i<n;i++){
            if(i<=maxpos){
                maxpos=max(maxpos,i+nums[i]);
                if(i==ends){
                    ends=maxpos;
                }
            }
        }
        return ends>=n-1;
    }
};
// @lc code=end

