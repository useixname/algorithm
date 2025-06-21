#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e4+5000;
int w[110],v[110],f[N];
int n,m,ans=0x7f7f7f7f;

signed main(){
    ios_base::sync_with_stdio(0);
    memset(f,0x7f7f7f7f,sizeof(f));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    f[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=m+5000-1;j++){
            f[j]=min(f[j],f[j-v[i]]+w[i]);
        }
    }
    for(int i=m;i<=m+5000-1;i++){
        ans=min(ans,f[i]);
    }
    cout<<ans;
    return 0;
}