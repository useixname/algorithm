#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int vis[N];
struct node{
    int id,w;
};
vector<node>e[N];
int n,s,ans;

int dfs(int u){
    vis[u]=1;
    int d1=0,d2=0;
    for(auto et:e[u]){
        if(vis[et.id]) continue;
        int d=dfs(et.id)+et.w;
        if(d>=d1) d2=d1,d1=d;
        if(d>d2) d2=d;
    }
    return d1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        int d=dfs(i);
        if(d<=s){
            ans=min(ans,d);
        }
    }
    cout<<ans;
    return 0;
}