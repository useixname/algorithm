#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,int>vis;
int n,ans;

int solve(int x){
    int maxn=x;
    while(x!=1){
        if(vis[x]) return vis[x];
        if(x&1) x=3*x+1;
        else x/=2;
        maxn=max(maxn,x);
    }
    vis[x]=maxn;
    return maxn;
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ans=max(ans,solve(i));
    }
    cout<<ans;
    return 0;
}