#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf INT_MIN
const int N=1e5+10;
int f[N],maxn[N],a[N];
int n,m,ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        f[i-1]=inf;
        for(int j=i;j<=n-(m-i);j++){
            f[j]=max(f[j-1],maxn[j-1])+a[j];
        }
        maxn[i-1]=inf;
        for(int j=i;j<=n-(m-i);j++){
            maxn[j]=max(f[j],maxn[j-1]);
        }
        ans=max(ans,*max_element(f+1,f+i+1));
    }
    cout<<ans;
    return 0;
}