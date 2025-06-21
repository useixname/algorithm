#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1145141,N=1e6+10;
int n,q;
int a[N],mul[N],inv[mod+1];


void init(){
    inv[1]=1;
    mul[0]=1;
    for(int i=1;i<=n;i++){
        mul[i]=mul[i-1]*a[i]%mod;
    }
    for(int i=2;i<=mod;i++){
        inv[i]=-(mod/i)*inv[mod%i];
        inv[i]=(inv[i]%mod+mod)%mod;
    }
}
//(mul[r]/mul[l-1])%mod=(mul[r]*inv[l-1])%mod
int soved(int l,int r){
    int ret=(mul[r]*inv[mul[l-1]])%mod;
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    init();
    int ans=0;
    while(q--){
        int l,r;
        cin>>l>>r;
        ans^=soved(l,r);
    }
    cout<<ans;
    return 0;
}