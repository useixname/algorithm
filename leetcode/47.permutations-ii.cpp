/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ret;
        ret.push_back(nums);
        while(next_permutation(nums.begin(),nums.end())){
            ret.push_back(nums);
        }
        return ret;
    }
};
// @lc code=end

