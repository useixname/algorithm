/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        int f[m+1][n+1];
        for(int i=1;i<=n;i++){
            f[1][i]=1;
        }
        for(int i=1;i<=m;i++){
            f[i][1]=1;
        }
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
        return f[m][n];
    }
};
// @lc code=end

