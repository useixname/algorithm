#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
typedef pair<int,int>PII;
queue<PII>q;
int net[8][2]={{2,1},{1,2},{-2,1},{-1,2},{-2,-1},{-1,-2},{2,-1},{1,-2}};
int n,m,x,y;
int a[N][N],dist[N][N];

void bfs(int x,int y){
    q.push({x,y});
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int tx=t.first+net[i][0],ty=t.second+net[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!dist[tx][ty]){
                dist[tx][ty]=dist[t.first][t.second]+1;
                q.push({tx,ty});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>x>>y;
    bfs(x,y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dist[i][j]==0){
                cout<<-1<<" ";
            }
            else if(i==x&&j==y){
                cout<<0<<" ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}