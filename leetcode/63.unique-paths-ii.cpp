/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        int f[n+1][m+1];
        memset(f,0,sizeof(f));
        for(int i=1;i<=m;i++){
            if(obstacleGrid[0][i-1]!=1) f[1][i]=1;
            else break;
        }
        for(int i=1;i<=n;i++){
            if(obstacleGrid[i-1][0]!=1) f[i][1]=1;
            else break;
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                if(obstacleGrid[i-1][j-1]!=1){
                    f[i][j]=f[i-1][j]+f[i][j-1];
                }
            }
        }
        return f[n][m];
    }
};
// @lc code=end

