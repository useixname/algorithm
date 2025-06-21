#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
int f[N][N];
int n,x;
int a[N],b[N],c[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(j>=c[i]){
                f[i][j]=max(max(f[i-1][j-c[i]]+b[i],f[i][j]),f[i-1][j]+a[i]);
            }
            else{
                f[i][j]=max(f[i-1][j]+a[i],f[i][j]);
            }
        }
    }
    cout<<f[n][x]*5;
    return 0;
}