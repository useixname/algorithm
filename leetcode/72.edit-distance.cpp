/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        int f[n+1][m+1];
        for(int i=0;i<=n;i++){
            f[i][0]=i;
        }
        for(int i=0;i<=m;i++){
            f[0][i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int a=f[i-1][j]+1;//É¾³ý
                int b=f[i][j-1]+1;//²åÈë
                int c=f[i-1][j-1];
                if(word1[i-1]!=word2[j-1]){
                    c+=1;//Ìæ»»
                }
                f[i][j]=min(c,min(a,b));
            }
        }
        return f[n][m];
    }
};
// @lc code=end

