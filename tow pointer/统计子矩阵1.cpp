#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
int a[N][N],sum[N][N];
int n,m,k,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            int h=1;
            for(int t=1;t<=n;t++){
                while(h<=t&&sum[t][j]-sum[t][i-1]-sum[h-1][j]+sum[h-1][i-1]>k){
                    h++;
                }
                if(h<=t) ans+=(t-h+1);
            }
        }
    }
    cout<<ans;
    return 0;
}