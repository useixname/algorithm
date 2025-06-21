#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7;
int f[N],prim[N],vis[N];
int cnt,ans;

void get_prim(){
    for(int i=2;i<=N;i++){
        if(!vis[i]) prim[++cnt]=i;
        for(int j=1;i*prim[j]<=N;j++){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0) break;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    get_prim();
    for(int i=1;i<=cnt;i++){
        prim[i]*=prim[i];
    }
    for(int i=1;i<=cnt;i++){
        if(prim[i]*prim[i]>23333333333333) break;
        for(int j=i+1;j<=cnt;j++){
            if(prim[i]*prim[j]>=2333&&prim[i]*prim[j]<=23333333333333){
                ans++;
            }
            if(prim[i]*prim[j]>23333333333333) break;
        }
    }
    cout<<ans;
    return 0;
}