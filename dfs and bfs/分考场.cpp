#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 110;  // n最多100
int a[MAXN][MAXN];     // 关系表：a[u][v]==1 表示 u 和 v 认识
int roomAssign[MAXN][MAXN]; // roomAssign[i][j] 表示第 i 个考场的第 j 个座位上坐的是第几个人（1-indexed）
int roomCount[MAXN];   // roomCount[i] 表示第 i 个考场目前已有多少人
int n, m;
int bestRooms = MAXN;  // 最优考场数量，全局最小值

// DFS: x 表示当前要安排的人（1-indexed），rooms 表示当前已使用的考场数
void dfs(int x, int rooms) {
    // 剪枝：如果当前考场数已经不小于全局最优，则不必继续
    if(rooms >= bestRooms) return;
    // 如果所有人都已安排，更新全局最优解
    if(x > n) {
        bestRooms = min(bestRooms, rooms);
        return;
    }
    // 尝试将第 x 个人放入已有的每个考场中
    for(int i = 1; i <= rooms; i++){
        bool canPlace = true;
        // 检查该考场已有的人，确保 x 与他们都不认识
        for(int j = 1; j <= roomCount[i]; j++){
            int other = roomAssign[i][j];
            if(a[x][other] == 1){ // 如果 x 和 other 认识，不能安排在同一考场
                canPlace = false;
                break;
            }
        }
        if(canPlace){
            roomCount[i]++;
            roomAssign[i][roomCount[i]] = x;
            dfs(x + 1, rooms);
            roomCount[i]--; // 回溯
        }
    }
    // 如果将 x 放入已有考场都不行，则开辟一个新的考场
    roomCount[rooms+1] = 1;
    roomAssign[rooms+1][1] = x;
    dfs(x + 1, rooms + 1);
    roomCount[rooms+1] = 0; // 回溯
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    // 初始化关系表 a[][] 为0
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    
    // 初始化 roomCount 数组为0
    memset(roomCount, 0, sizeof(roomCount));
    // 先把第1个人安排到第1个考场
    roomCount[1] = 1;
    roomAssign[1][1] = 1;
    dfs(2, 1);
    
    cout << bestRooms << "\n";
    return 0;
}
