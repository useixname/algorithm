/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        nums.push_back(INT_MAX);
        int n=nums.size();
        if(!n) return {-1,-1};
        int l=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int r=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(nums[l]==target&&nums[r-1]==target){
            return {l,r-1};
        }
        else{
            return {-1,-1};
        }
    }
};
// @lc code=end

