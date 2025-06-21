#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+10,mod=998244353;
int n,m;
int f[N],inv[N];

void init(){
    inv[0]=inv[1]=1;
    f[0]=1;
    for(int i=1;i<=m;i++){
        f[i]=f[i-1]*i%mod;
    }
    for(int i=2;i<=m;i++){
        inv[i]=-(mod/i)*inv[mod%i];
        inv[i]=(inv[i]%mod+mod)%mod;
    }
    for(int i=1;i<=m;i++){
        inv[i]=inv[i-1]*inv[i]%mod;
    }
}

int soved(int l,int r){
    int ret=(f[l]*inv[r]%mod*inv[l-r]%mod)%mod;
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    init();
    int ans=0;
    while(n--){
        int l,r;
        cin>>l>>r;
        // cout<<soved(l,r)<<'\n';
        ans^=soved(l,r);
    }
    cout<<ans;
    return 0;
}