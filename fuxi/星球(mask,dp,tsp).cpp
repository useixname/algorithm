#include<bits/stdc++.h>
using namespace std;
const int N=20;
double f[1<<N][N],x[N],y[N],z[N],w[N],dist[N][N];
int n;

double dis(int i,int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>z[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dist[i][j]=dist[j][i]=dis(i,j);
        }
    }
    double inf=1e18;
    for(int mask=1;mask<(1<<n);mask++){
        for(int k=1;k<=n;k++){
            f[mask][k]=inf;
        }
    }
    for(int i=1;i<=n;i++){
        f[1<<(i-1)][i]=0.0;
    }
    for(int mask=1;mask<(1<<n);mask++){
        for(int k=1;k<=n;k++){
            if((mask&(1<<(k-1)))==0) continue;
            if(f[mask][k]==inf) continue;
            for(int j=1;j<=n;j++){
                if((mask&(1<<(j-1)))!=0) continue;
                int new_mask=mask|(1<<(j-1));
                f[new_mask][j]=min(f[new_mask][j],f[mask][k]+dist[k][j]*w[j]);
            }
        }
    }
    double ans=inf;
    int full_mask=(1<<n)-1;
    for(int k=1;k<=n;k++){
        ans=min(ans,f[full_mask][k]);
    }
    printf("%.2f",ans);
    return 0;
}