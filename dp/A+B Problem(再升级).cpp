#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int vis[N],prim[N],f[N];
int n,cnt=1;

void get_prim(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            prim[cnt++]=i;
        }
        for(int j=1;1ll*i*prim[j]<=n;j++){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0){
                break;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    get_prim(n);
    // for(int i=1;i<=cnt-1;i++){
    //     cout<<prim[i]<<" ";
    // }
    // cout<<'\n';
    f[0]=1;
    // 组合型枚举，先枚举硬币，再枚举金额。
    for(int i=1;i<=cnt-1;i++){
        for(int j=0;j<=n;j++){
            if(j>=prim[i]){
                f[j]=f[j]+f[j-prim[i]];
            }
        }
    }
    cout<<f[n];
    return 0;
}