#include<bits/stdc++.h>
using namespace std;
const int N=150;
int a[N][N],f[N];
int n,ans=-0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            a[i][j]+=a[i-1][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=i;k++){
            memset(f,0,sizeof(f));
            for(int j=1;j<=n;j++){
                int x=a[i][j]-a[i-k][j];
                f[j]=max(f[j-1]+x,x);
                ans=max(ans,f[j]);
            }
        }
    }
    cout<<ans;
    return 0;
}