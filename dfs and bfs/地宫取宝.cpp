#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 55;
const int mod = 1e9 + 7;
int a[N][N];
// dp[x][y][cnt][max_idx]：当前位置 (x,y)，已拿 cnt 件宝物，当前最大宝物的值为 max_idx
int dp[N][N][15][15];
int n, m, k;

int dfs(int x, int y, int cnt, int max_idx) {
    if (dp[x][y][cnt][max_idx])
        return dp[x][y][cnt][max_idx];
    
    // 到达出口时判断是否正好拿到 k 件宝物
    if (x == n && y == m) {
        return dp[x][y][cnt][max_idx] = (cnt == k ? 1 : 0);
    }
    int res = 0;
    
    // 向下走： (x+1, y)
    if (x + 1 <= n) {
        int nextVal = a[x+1][y];
        // 方案1：不拿当前格子的宝物
        res = (res + dfs(x+1, y, cnt, max_idx)) % mod;
        // 方案2：如果允许拿，则拿取宝物
        if (cnt < k && nextVal > max_idx) {
            res = (res + dfs(x+1, y, cnt + 1, nextVal)) % mod;
        }
    }
    
    // 向右走： (x, y+1)
    if (y + 1 <= m) {
        int nextVal = a[x][y+1];
        // 方案1：不拿当前格子的宝物
        res = (res + dfs(x, y+1, cnt, max_idx)) % mod;
        // 方案2：如果允许拿，则拿取宝物
        if (cnt < k && nextVal > max_idx) {
            res = (res + dfs(x, y+1, cnt + 1, nextVal)) % mod;
        }
    }

    return dp[x][y][cnt][max_idx] = res;  //最重要的一步
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            // 所有宝物值加 1，使得 0 表示“还没拿宝物”的状态，
            // 而实际宝物值 v 会变为 v+1，方便后续比较
            a[i][j] += 1;
        }
    }
    
    // 从入口 (1,1) 出发有两种选择：
    // 1. 不拿宝物：状态 (1,1,0,0)
    // 2. 拿宝物：状态 (1,1,1, a[1][1])
    cout << (dfs(1,1,0,0) + dfs(1,1,1,a[1][1])) % mod;
    return 0;
}
