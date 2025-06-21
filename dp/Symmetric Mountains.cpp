#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int a[N],f[N][N];
int n,ans=0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int len=1;len<=n;len++){
        ans=0x3f3f3f3f;
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            f[i][j]=f[i+1][j-1]+fabs(a[i]-a[j]);
            ans=min(ans,f[i][j]);
        }
        cout<<ans<<" ";
    }
    return 0;
}