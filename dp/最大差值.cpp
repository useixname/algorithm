#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int a[N],f[N];
int n,ans=-3e10;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    f[0]=3e10;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=min(f[i-1],a[i]);
    }
    for(int j=2;j<=n;j++){
        ans=max(a[j]-f[j-1],ans);
    }
    cout<<ans;
    return 0;
}