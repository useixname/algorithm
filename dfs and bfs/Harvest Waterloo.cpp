#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int N=1e5+10;
int net[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
char a[N][1000];
int n,m,s,t;
queue<PII>q;

int bfs(int s,int t){
    int ret=0;
    if(a[s][t]=='S') ret+=1;
    else if(a[s][t]=='M') ret+=5;
    else ret+=10;
    a[s][t]='*';
    q.push({s,t});
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=t.first+net[i][0],ty=t.second+net[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]!='*'){
                if(a[tx][ty]=='S') ret+=1;
                else if(a[tx][ty]=='M') ret+=5;
                else ret+=10;
                q.push({tx,ty});
                a[tx][ty]='*';
            }
        }
    }
    return ret;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    cin>>s>>t;
    cout<<bfs(s+1,t+1);
    return 0;
}