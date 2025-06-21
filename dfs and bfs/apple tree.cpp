#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=25;
int w[N];
int t,n,m,ans;

void dfs(int u,int s){
    if(s>m) return;
    if(u>=n){
        ans=max(ans,s);
        return;
    }
    dfs(u+1,s+w[u]);
    dfs(u+1,s);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>w[i];
        }
        sort(w+1,w+n+1);
        dfs(0,0);
        cout<<ans<<'\n';
    }
    return 0;
}