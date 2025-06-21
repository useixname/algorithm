#include<bits/stdc++.h>
using namespace std;
#define inf 1<<30
const int N=2e5+10;
int a[N],f[N],ans=-inf;
int n,l,r;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>l>>r;
    memset(f,0xcf,sizeof(f));
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    f[0]=0;
    for(int i=l;i<=n+r;i++){
        for(int j=max(0,i-r);j<=i-l;j++){
            f[i]=max(f[j]+a[i],f[i]);
        }
        if(i>=n-r+1) ans=max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}