#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,mod=1e9+10;
int f[N];
int n,a,b,c;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>a>>b>>c;
    f[c]=1;
    for(int i=c+1;i<=n;i++){
        f[i] = ((i-a <= c ? 1 : f[i-a])+(i-b <= c ? 1 : f[i-b]))%1000000007;
    }
    cout<<f[n]%mod;
    return 0;
}