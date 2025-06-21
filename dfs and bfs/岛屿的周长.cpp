#include<bits/stdc++.h>
using namespace std;
const int N=55;
int net[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int a[N][N];
int n,m,ans;

int chk(int x,int y){
    int ret=0;
    for(int i=0;i<4;i++){
        int tx=x+net[i][0],ty=y+net[i][1];
        if(tx>=0&&tx<=n+1&&ty>=0&&ty<=m+1&&a[tx][ty]==0){
            ret++;
        }
    }
    return ret;
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
            if(a[i][j]==1){
                ans+=chk(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}