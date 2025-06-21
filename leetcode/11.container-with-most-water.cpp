/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int st=0,et=n-1,ret=0;
        while(st<et){
            int t=(et-st)*min(height[et],height[st]);
            ret=max(ret,t);
            if(height[st]<=height[et]) st++;
            else et--;
        }
        return ret;
    }
};
// @lc code=end

