#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10,mod=1000000007;
int f[N],inv[N],mul[N];
int t;

void init(){
    f[1]=0;f[2]=1;f[3]=2;
    for(int i=4;i<=N;i++){
        f[i]=(i-1)*(f[i-1]+f[i-2])%mod;
    }
    inv[0]=inv[1]=1;
    mul[0]=1;
    for(int i=1;i<=N;i++){
        mul[i]=mul[i-1]*i%mod;
    }
    for(int i=2;i<=N;i++){
        inv[i]=-(mod/i)*inv[mod%i];
        inv[i]=(inv[i]%mod+mod)%mod;
    }
    for(int i=1;i<=N;i++){
        inv[i]=inv[i-1]*inv[i]%mod;
    }
}

int soved(int n,int m){
    if (n - m == 1) return 0;
    else if (m == n) return 1;
    else if (m == 0) return f[n];
    int ret=mul[n]*inv[n-m]%mod*inv[m]%mod*f[n-m]%mod;
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    init();
    while(t--){
        int n,m;
        cin>>n>>m;
        printf("%lld\n",soved(n,m));
    }
    return 0;
}