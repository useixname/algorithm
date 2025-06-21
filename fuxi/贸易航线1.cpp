#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int f[N][11][2],a[N][11];
int n,m,k,ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    memset(f,INT_MIN,sizeof(f));
    f[0][0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!=-1){
                f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]+a[i][j]);
            }
        }
        for(int j=1;j<=m;j++){
            if(a[i][j]!=-1){
                f[i][j][1]=max(f[i-1][j][1],f[i-1][j][0]-a[i][j]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        // cout<<f[n][i][0]<<" ";
        ans=max(ans,f[n][i][0]);
    }
    cout<<ans*k;
    return 0;
}