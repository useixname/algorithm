#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int dp[N][N],p[N][N];
int n,m,t;

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(max(dp[i][k],dp[k][j]),dp[i][j]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    memset(dp,0x3f3f3f3f,sizeof(dp));
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dp[u][v]=w;
    }
    floyd();
    while(t--){
        int s,p;
        cin>>s>>p;
        if(dp[s][p]==0x3f3f3f3f){
            cout<<-1;
        }
        else{
            cout<<dp[s][p];
        }
        cout<<'\n';
    }
    return 0;
}