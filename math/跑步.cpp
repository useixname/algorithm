#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+10,mod=998244353;
int prim[N],vis[N],inv[N];
int n,cnt,p=1,ans;

void get_prim(){
    for(int i=2;i<=n;i++){
        if(!vis[i]) prim[++cnt]=i;
        for(int j=1;i*prim[j]<=n;j++){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0) break;
        }
    }
}

void get_inv(){
    inv[1]=1;
    for(int i=2;i<=n;i++){
        inv[i]=-(mod/i)*inv[mod%i];
        inv[i]=(inv[i]%mod+mod)%mod;
    }
}

void get_lcm(){
    for(int i=1;i<=cnt;i++){
        int t=1;
        while(t<=n){
            t*=prim[i];
        }
        t/=prim[i];
        p=p*t%mod;
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    get_prim();
    get_lcm();
    get_inv();
    for(int i=1;i<=n;i++){
        int ops=p*inv[i]%mod;
        ans=(ans+ops*(n-2*i+1)%mod+mod)%mod;
    }
    cout<<ans;
    return 0;
}