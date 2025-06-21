#include<bits/stdc++.h>
using namespace std;
const int N=20;
int f[N],ret[N],w[N][N];
int n,m,ans;

void dfs(int u,int sum,int t){
    if(t<0) return;
    if(u==n+1){
        if(sum>ans){
            ans=sum;
            for(int i=1;i<=n;i++){
                f[i]=ret[i];
            }
        }
        return;
    }
    for(int i=0;i<=m;i++){
        ret[u]=i;
        dfs(u+1,sum+w[u][i],t-i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>w[i][j];
        }
    }
    dfs(1,0,m);
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<f[i]<<'\n';
    }
    return 0;
}