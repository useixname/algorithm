/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        int ret[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ret[i][j]=matrix[n-j-1][i];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=ret[i][j];
            }
        }
    }
};
// @lc code=end

