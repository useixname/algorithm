#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;

char a[N][N];
int vis[N][N];
int n, m, ans;

// 如果上方没“搭”或当前位置是障碍，就不能放置；否则返回 true
bool chk(int x, int y) {
    if (!vis[x - 1][y]) return false;
    return true;
}

void dfs(int x, int y) {
    // 到了第 n+1 行，说明前 n 行都处理完，合法方案数 +1
    if (x == n + 1) {
        ans++;
        return;
    }

    // 如果列索引超过 m，说明这一行结束，需要做“行内连续性”检查
    if (y == m + 1) {
        // 遍历第 x 行，检查是否存在孤立的“已铺”点
        int l=m+1,r=0;
        for (int i = 1; i <= m; i++) {
            if (vis[x][i]) {
                l=min(l,i);
                r=max(r,i);
            }
        }
        if(r==0){
            dfs(x+1,1);
            return;
        }
        for(int i=l;i<=r;i++){
            if(!vis[x][i]){
                return;
            }
        }
        dfs(x + 1, 1);
        return;
    }
     // ----- 1. 不放当前位置，直接去下一个格子 -----
    // 无论该格是不是 'X'，都应该允许“空着”不放
    dfs(x, y+1);

    // ----- 2. 如果当前格子可以放，就尝试放置 -----
    if(a[x][y]!='X'){
        if(chk(x,y)){
            vis[x][y]=1;
            dfs(x,y+1);
            vis[x][y]=0;
            // 仅仅是把刚才“放”的状态撤销，以便让父节点或后续分支看到“(x,y) 未放” 的干净状态。
            // 它并不会重新调用 dfs(x,y+1)，也不算入额外的“(x,y) 不放”方案。
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    // 输入时注意你原本是倒序读：从 a[n][1] → a[1][m]
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    // 边界初始化：第 0 行视为都“已铺”，第 m+1 列也都“已铺”
    for (int i = 1; i <= m; i++) vis[0][i] = 1;
    for (int i = 1; i <= n; i++) vis[i][m + 1] = 1,vis[i][0]=1;

    dfs(1, 1);
    cout << ans;
    return 0;
}
