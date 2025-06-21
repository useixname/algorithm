/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    int n,m;
    vector<int> ret;
    void dfs(vector<vector<int>>& matrix,vector<vector<int>>& vis,int x,int y,char ch){
        if(x<0||x>=n||y<0||y>=m||vis[x][y]) return;
        vis[x][y]=true;
        ret.push_back(matrix[x][y]);
        if(ch=='r'){
            if(y==m-1||vis[x][y+1]){
                dfs(matrix,vis,x+1,y,'d');
            }
            else{
                dfs(matrix,vis,x,y+1,'r');
            }
        }
        else if(ch=='d'){
            if(x==n-1||vis[x+1][y]){
                dfs(matrix,vis,x,y-1,'l');
            }
            else{
                dfs(matrix,vis,x+1,y,'d');
            }
        }
        else if(ch=='l'){
            if(y==0||vis[x][y-1]){
                dfs(matrix,vis,x-1,y,'u');
            }
            else{
                dfs(matrix,vis,x,y-1,'l');
            }
        }
        else if(ch=='u'){
            if(x==0||vis[x-1][y]){
                dfs(matrix,vis,x,y+1,'r');
            }
            else{
                dfs(matrix,vis,x-1,y,'u');
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>>vis(n+1,vector<int>(m+1,false));
        dfs(matrix,vis,0,0,'r');
        return ret;
    }
};
// @lc code=end

