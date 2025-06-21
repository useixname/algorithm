#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10;
int v[N],w[N],a[N],f[N][N];
int n,m,t;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>t;
    for(int i=1;i<=t;i++){
        cin>>a[i]>>v[i]>>w[i];
    }
    for(int k=1;k<=t;k++){
        for(int i=n;i>=v[k];i--){
            for(int j=m;j>=w[k];j--){
                f[i][j]=max(f[i][j],f[i-v[k]][j-w[k]]+a[k]);
            }
        }
    }
    cout<<f[n][m];
    return 0;
}