#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=100000000;
int f[N][1010],a[N];
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]%=m;
        f[i][a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            f[i][j]+=(f[i-1][j]%mod+f[i-1][(j-a[i]+m)%m]%mod)%mod;
        }
    }
    cout<<f[n][0];
    return 0;
}