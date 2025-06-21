#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int id,w;
};
int vis[N];
vector<node>e[N];
int n,ans;

int dfs(int u){
    vis[u]=1;
    int d1=0,d2=0;
    for(auto t:e[u]){
        if(vis[t.id]) continue;
        int d=dfs(t.id)+t.w;
        if(d>=d1) d2=d1,d1=d;
        else if(d>d2) d2=d;
    }
    ans=max(ans,d1+d2);
    return d1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1);
    printf("%lld",10*ans+ans*(ans+1ll)/2);
    return 0;
}