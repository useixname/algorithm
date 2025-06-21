#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int M=1000000007;
int n,cnt;
int prim[N],vis[N];

void get_prim(){
    for(int i=2;i<=n;i++){
        if(!vis[i]) prim[++cnt]=i;
        for(int j=1;i*prim[j]<=n;j++){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0) break;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    get_prim();
    for(int i=1;i<=cnt;i++){
        int ret=1;
        while(ret<=n){
            ret*=prim[i];
        }
        ret/=prim[i];
        prim[i]=ret;
    }
    int ans=1;
    for(int i=1;i<=cnt;i++){
        ans=ans*prim[i]%M;
    }
    cout<<ans;
    return 0;
}