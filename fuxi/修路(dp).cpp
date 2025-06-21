#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e3+10;
double f[N][N][2],a[N],b[N];
int n,m,d;

double dis(int x,int y){
    double ret=sqrt((a[x]-b[y])*(a[x]-b[y])+d*d);
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    const double INF = 1e18;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            f[i][j][0] = f[i][j][1] = INF;
        }
    }
    f[1][0][0]=a[1];
    f[0][1][1]=dis(0,1);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i){
                f[i][j][0]=min(f[i][j][0],min(f[i-1][j][0]+a[i]-a[i-1],f[i-1][j][1]+dis(i,j)));
            }
            if(j){
                f[i][j][1]=min(f[i][j][1],min(f[i][j-1][1]+b[j]-b[j-1],f[i][j-1][0]+dis(i,j)));
            }
        }
    }
    printf("%.2f",min(f[n][m][0],f[n][m][1]));
    return 0;
}