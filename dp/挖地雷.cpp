#include<bits/stdc++.h>
using namespace std;
const int N=25;
int f[N],a[N],b[N][N],path[N],vis[N];
int n,ans,cnt,t;

void dfs(int x){
    if(path[x]) dfs(path[x]);
    cout<<x<<" ";
}

// 0 1 1 3 4
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        b[0][i]=1;
        for(int j=i+1;j<=n;j++){
            cin>>b[i][j];
        }
    }
    b[0][n]=1;
    for(int i=1;i<=n;i++){
        path[i]=i;
        for(int j=0;j<i;j++){
            if(b[j][i]==1){
                if(f[i]<f[j]+a[i]){
                    f[i]=f[j]+a[i];
                    path[i]=j;
                }
            }
        }
        if(f[i]>ans){
            ans=f[i];
            t=i;
        }
    }
    dfs(t);
    cout<<'\n'<<ans;
    return 0;
}