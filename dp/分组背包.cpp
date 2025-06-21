#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int v[N],w[N],s[N],f[N][N];
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i]>>s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=s[i]&&k*w[i]<=j;k++){
                f[i][j]=max(f[i][j],f[i-1][j-k*w[i]]+k*v[i]);
            }
        }
    }
    cout<<f[n][m];
    return 0;
}