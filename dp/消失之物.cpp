#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int w[N],dp[N]={1},f[N]={1};
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            dp[j]=(dp[j]+dp[j-w[i]])%10;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j>=w[i]) f[j]=(dp[j]-f[j-w[i]]+10)%10;
            else f[j]=dp[j]%10;
            cout<<f[j];
        }
        cout<<'\n';
    }
    return 0;
}