#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int N=1e2+10;
int f[N][N];
int n,m;

void floyd(){
    for(int k=1;k<=n;k++){
        f[k][k]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(f[i][k]!=inf&&f[k][j]!=inf){
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    memset(f,inf,sizeof(f));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        f[u][v]=min(f[u][v],w);
        f[v][u]=f[u][v];
    }
    floyd();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<f[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}