#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10;
int a[N][N],sum[N][N];
int n,m,k,ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]+a[i][j]-sum[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int x=i;x<=n;x++){
                for(int y=j;y<=m;y++){
                    int t=sum[x][y]-sum[x][j-1]-sum[i-1][y]+sum[i-1][j-1];
                    if(t<=k) ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}