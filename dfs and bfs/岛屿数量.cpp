#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=55;
int net[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[N][N];
int n,m,ans;

void bfs(int x,int y){
    queue<PII>q;
    q.push({x,y});
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=t.first+net[i][0],ty=t.second+net[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]==1){
                a[tx][ty]=0;
                q.push({tx,ty});
            }
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
            if(a[i][j]==1){
                ans++;
                bfs(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}