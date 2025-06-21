#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
int vis[N][N],net[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
char a[N][N];
int n,m,ans;

void bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=t.first+net[i][0],ty=t.second+net[i][1];
            if(tx>=1&&tx<=n+2&&ty>=1&&ty<=m+2&&a[tx][ty]!='*'){
                a[tx][ty]='*';
                q.push({tx,ty});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n+2;i++){
        for(int j=1;j<=m+2;j++){
            a[i][j]='0';
        }
    }
    for(int i=2;i<=n+1;i++){
        for(int j=2;j<=m+1;j++){
            cin>>a[i][j];
        }
    }
    bfs(1,1);
    a[1][1]='*';
    for(int i=2;i<=n+1;i++){
        for(int j=2;j<=m+1;j++){
            if(a[i][j]=='0'){
                ans++;
            }
        }
    }
    // for(int i=1;i<=n+2;i++){
    //     for(int j=1;j<=m+2;j++){
    //         cout<<a[i][j];
    //     }
    //     cout<<'\n';
    // }
    cout<<ans;
    return 0;
}