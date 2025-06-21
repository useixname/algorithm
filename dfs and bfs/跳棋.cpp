#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int a[N][N],vis[N][N],net[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,sx,sy,ans;

void dfs(int x,int y,int sum){
    ans=max(ans,sum);
    for(int i=0;i<4;i++){
        int tx=x+net[i][0],ty=y+net[i][1];
        while(tx>=1&&tx<=n&&ty>=1&&ty<=n&&a[tx][ty]!=0){
            tx+=net[i][0],ty+=net[i][1];
        }
        if(tx>=1&&tx<=n&&ty>=1&&ty<=n&&!vis[tx][ty]&&!a[tx][ty]&&abs(x-tx)+abs(y-ty)!=1){
            vis[tx][ty]=1;
            dfs(tx,ty,sum+abs(x-tx)+abs(y-ty));
            vis[tx][ty]=0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>sx>>sy;
    vis[sx][sy]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dfs(sx,sy,0);
    cout<<ans;
    return 0;
}