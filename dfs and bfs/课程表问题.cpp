#include<bits/stdc++.h>
using namespace std;
int numCourses;
vector<vector<int>> prerequisites;

class Solution {
public:
    vector<vector<int>> grid;
    int vis[2010];
    // 三色标记法
    bool dfs(int u) {
        vis[u] = 1; // 标记为访问中
        for (int v : grid[u]) {
            if (vis[v] == 1) return true; // 如果节点已经访问中，说明有环
            if (vis[v] == 0) { // 如果未访问，递归访问
                if (dfs(v)) return true;
            }
        }
        vis[u] = 2; // 标记为访问完成
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 初始化邻接表
        grid.resize(numCourses);
        memset(vis, 0, sizeof(vis)); // 初始化访问数组
        
        // 构建邻接表
        for (const auto& edge : prerequisites) {
            grid[edge[1]].push_back(edge[0]);
        }
        
        // 检测每个节点是否有环
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) { // 如果未访问，进行深度优先搜索
                if (dfs(i)) return false;
            }
        }
        
        return true; // 如果没有环，返回 true
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Solution s;
    cin>>numCourses;

    s.canFinish(numCourses,prerequisites);
    return 0;
}