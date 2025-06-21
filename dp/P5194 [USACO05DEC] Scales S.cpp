#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
int a[N],sum[N];
int n,c,ans;

void dfs(int u,int s){
    if(s>c) return;
    if(sum[u-1]+s<=c){
        ans=max(ans,sum[u-1]+s);
        return;
    }
    ans=max(ans,s);
    for(int i=1;i<=u-1;i++){
        dfs(i,s+a[i]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    dfs(n+1,0);
    cout<<ans;
    return 0;
}