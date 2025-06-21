#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int a[N],sum[N];
int n,k,ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n-k;i++){
        int x=sum[i+k]-sum[i-1];
        ans=max(ans,x);
    }
    cout<<ans;
    return 0;
}