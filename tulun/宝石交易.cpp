#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int N=1e4+10;
int a[2*N],b[N];
int n,m,ans=inf;
int f[415][415];

void floyd(){
    for(int i=1;i<=410;i++){
        for(int j=1;j<=410;j++){
            for(int k=1;k<=410;k++){
                if(f[i][k]!=inf&&f[k][j]!=inf){
                    f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
                }
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=410;i++){
        f[i][i]=0;
        for(int j=i+1;j<=410;j++){
            f[i][j]=f[j][i]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int j=1;j<=n;j++){
        cin>>b[j];
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        f[u][v]=min(w,f[u][v]);
    }
    floyd();
    for(int i=1;i<=n;i++){
        int tot=0;
        for(int j=1;j<=n;j++){
            int t=min(f[a[i+j-1]][b[j]],f[b[j]][a[i+j-1]]);
            if(t==inf) {tot=inf;break;};
            tot+=t;
        }
        ans=min(ans,tot);
    }
    if(ans==inf) cout<<-1;
    else cout<<ans;
    return 0;
}