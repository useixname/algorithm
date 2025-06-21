#include<bits/stdc++.h>
using namespace std;
const int N=110;
int net[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int a[N][N];
bool first_border[N][N],second_border[N][N];
int n,m;

void dfs1(int x,int y){
    first_border[x][y]=true;
    for(int i=0;i<4;i++){
        int tx=x+net[i][0],ty=y+net[i][1];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]>=a[x][y]&&!first_border[tx][ty]){
            dfs1(tx,ty);
        }
    }
}

void dfs2(int x,int y){
    second_border[x][y]=true;
    for(int i=0;i<4;i++){
        int tx=x+net[i][0],ty=y+net[i][1];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]>=a[x][y]&&!second_border[tx][ty]){
            dfs2(tx,ty);
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
        dfs1(i,1);
        dfs2(i,m);
    }
    for(int j=1;j<=m;j++){
        dfs1(1,j);
        dfs2(n,j);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(first_border[i][j]&&second_border[i][j]){
                cout<<i-1<<" "<<j-1<<'\n';
            }
        }
    }
    return 0;
}