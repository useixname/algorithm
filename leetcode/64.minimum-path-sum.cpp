/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int f[n+1][m+1];
        memset(f,0,sizeof(f));
        for(int i=1;i<=m;i++){
            f[1][i]=f[1][i-1]+grid[0][i-1];
        }
        for(int i=1;i<=n;i++){
            f[i][1]=f[i-1][1]+grid[i-1][0];
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                f[i][j]=min(f[i-1][j],f[i][j-1])+grid[i-1][j-1];
            }
        }
        return f[n][m];
    }
};
// @lc code=end

