#include<bits/stdc++.h>
using namespace std;
const int N=155;
int a[N][N],sum[N][N];
int n,m,ans=-0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    m=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    for(int x1=1;x1<=n;x1++){
        for(int y1=1;y1<=m;y1++){
            for(int x2=x1;x2<=n;x2++){
                for(int y2=y1;y2<=m;y2++){
                    int maxn=sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
                    ans=max(maxn,ans);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}