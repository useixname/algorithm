#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
int net[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
const int N=1e2+10;
int d[N][N];
char g[N][N];
int n,nx,ny,ex,ey;

int bfs(int x,int y){
    queue<PII>q;
    q.push({x,y});
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=t.first+net[i][0],ty=t.second+net[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=n&&!d[tx][ty]&&g[t.first][t.second]!=g[tx][ty]){
                d[tx][ty]=d[t.first][t.second]+1;
                q.push({tx,ty});
                if(tx==ex&&ty==ey){
                    return d[tx][ty];
                }
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
            if(g[i][j]=='A'){
                nx=i;
                ny=j;
            }
            if(g[i][j]=='B'){
                ex=i;
                ey=j;
            }
        }
    }
    cout<<bfs(nx,ny);
    return 0;
}