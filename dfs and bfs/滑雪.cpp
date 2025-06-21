#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int net[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int a[N][N],dp[N][N];
int n,m,ans=0;;


int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int tx = x + net[i][0], ty = y + net[i][1];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] < a[x][y]) {
            dp[x][y] = max(dp[x][y], dfs(tx, ty) + 1);
        }
    }
    return dp[x][y];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans=max(dfs(i,j),ans);
        }
    }
    cout<<ans;
    return 0;
}