#include<bits/stdc++.h>
using namespace std;
const int N=25;
int vis[N];
struct node{
    int v,w;
};
vector<node>e[N];
int n,m,ans,maxn;

void dfs(int u,int s){
    ans=max(ans,s);
    for(auto eu:e[u]){
        int v=eu.v,w=eu.w;
        if(!vis[v]){
            vis[v]=1;
            dfs(v,s+w);
            vis[v]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++){
        vis[i]=1;
        ans=0;
        dfs(i,0);
        vis[i]=0;
        maxn=max(maxn,ans);
    }
    cout<<maxn;
    return 0;
}