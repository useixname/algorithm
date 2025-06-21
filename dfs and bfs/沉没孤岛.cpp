#include<bits/stdc++.h>
using namespace std;
const int N=55;
int net[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[N][N];
int n,m;

void dfs(int x,int y,int c){
    a[x][y]=c;
    for(int i=0;i<4;i++){
        int tx=x+net[i][0],ty=y+net[i][1];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]==1){
            dfs(tx,ty,c);
        }
    }
}

bool chk(int x,int y){
    if((x==1||y==1||x==n||y==m)&&a[x][y]==1) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        if(a[1][i]==1) dfs(1,i,2);
        if(a[n][i]==1) dfs(n,i,2);
    }
    for(int j=1;j<=n;j++){
        if(a[j][1]==1) dfs(j,1,2);
        if(a[j][m]==1) dfs(j,m,2);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==1){
                dfs(i,j,0);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==2){
                cout<<1<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}