#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int f[N][N],a[N];
int n,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i][i]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            f[i][j]=min(f[i][j-1],a[j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans=max((j-i+1)*f[i][j],ans);
        }
    }
    cout<<ans;
    return 0;
}