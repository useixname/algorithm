#include<bits/stdc++.h>
using namespace std;
const int N=35;
typedef pair<int,int>PII;
int net[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int a[N][N],dist[N][N];
int n;
queue<PII>q;

void bfs(int x,int y){
    q.push({x,y});
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=t.first+net[i][0],ty=t.second+net[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=n&&a[tx][ty]==0&&a[tx][ty]!=1){
                a[tx][ty]=3;
                q.push({tx,ty});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1||j==1||i==n||j==n){
                if(a[i][j]==0){
                    a[i][j]=3;
                    bfs(i,j);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==3){
                cout<<0<<" ";
            }
            else if(a[i][j]==0){
                cout<<2<<" ";
            }
            else{
                cout<<1<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}