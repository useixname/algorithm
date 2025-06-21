#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
char a[N][N];
int vis[N][N],net[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int n,m,ans;

void dfs(int x,int y){
    a[x][y]='#';
    for(int i=0;i<4;i++){
        int tx=x+net[i][0],ty=y+net[i][1];
        if(tx>=1&&tx<=n&ty>=1&&ty<=m&&a[tx][ty]=='.'){
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
    vis[1][1]=1;
    dfs(1,1);
    if(a[n][m]=='#') cout<<"Yes";
    else cout<<"No";
    return 0;
}