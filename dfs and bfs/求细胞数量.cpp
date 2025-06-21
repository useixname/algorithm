#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int vis[N][N],net[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
char a[N][N];
int n,m,ans;

void dfs(int x,int y){
    a[x][y]='0';
    for(int i=0;i<4;i++){
        int tx=x+net[i][0],ty=y+net[i][1];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!vis[tx][ty]&&a[tx][ty]!='0'){
            vis[tx][ty]=1;
            dfs(tx,ty);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!='0'){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}