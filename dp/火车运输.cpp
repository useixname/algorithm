#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int f[N][N],w[N];
int n,a,b,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    // f[k][i][j]=max(f[k-1][i-w[k]][j]+w[k],f[k-1][i][j-w[i]]+w[k],f[k-1][i][j]);
    for(int k=1;k<=n;k++){
        for(int i=a;i>=0;i--){
            for(int j=b;j>=0;j--){
                if(i>=w[k]) f[i][j]=max(f[i][j],f[i-w[k]][j]+w[k]);
                if(j>=w[k]) f[i][j]=max(f[i][j],f[i][j-w[k]]+w[k]);
                ans=max(ans,f[i][j]);
            }
        }
    }
    cout<<ans;
    return 0;
}