#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,mod=998244353;
int f[N],g[N];
int t,n,m;

void init(){
    f[1]=8,g[1]=1;
    for(int i=2;i<=N;i++){
        f[i]=f[i-1]*9+g[i-1];
        g[i]=g[i-1]*9+f[i-1];
        f[i]%=mod;
        g[i]%=mod;
    }
}
signed main(){
    scanf("%d",&t);
    init();
    while(t--){
        scanf("%d %d",&n,&m);
        if(n==1) printf("9\n");
        else{
            printf("%lld\n",f[n]%mod);
        }
    }
    return 0;
}