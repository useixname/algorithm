#include<bits/stdc++.h>
using namespace std;
const int N=255;
int f_min[N][N],f_max[N][N],w[N],sum[N];
int n,ans_min=0x3f3f3f3f,ans_max;

int main(){
    ios_base::sync_with_stdio(0);
    memset(f_min,0x3f3f3f3f,sizeof(f_min));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        w[n+i]=w[i];
    }
    for(int i=1;i<=2*n;i++){
        f_min[i][i]=f_max[i][i]=0;
        sum[i]=sum[i-1]+w[i];
    }
    for(int len=1;len<=n;len++){
        for(int i=1;i+len-1<=2*n;i++){
            int j=i+len-1;
            for(int k=i;k<j;k++){
                f_min[i][j]=min(f_min[i][k]+f_min[k+1][j]+sum[j]-sum[i-1],f_min[i][j]);
                f_max[i][j]=max(f_max[i][k]+f_max[k+1][j]+sum[j]-sum[i-1],f_max[i][j]);
            }
        }
    }
    for(int i=1;i<=n+1;i++){
        ans_min=min(ans_min,f_min[i][i+n-1]);
        ans_max=max(ans_max,f_max[i][i+n-1]);
    }
    cout<<ans_min<<'\n'<<ans_max;
    return 0;
}