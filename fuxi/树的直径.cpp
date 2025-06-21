#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int v,w;
};
vector<node>e[N];
int b[N],s[N],vis[N];
int n,ans;

int dfs(int u){
    vis[u]=1;
    int d1=0;
    int d2=0;
    for(auto eu:e[u]){
        int v=eu.v,w=eu.w;
        if(vis[v]) continue;
        vis[v]=1;
        int d=dfs(v)+w;
        if(d>=d1) d2=d1,d1=d;
        else if(d>d2) d2=d;
    }
    ans=max(ans,d1+d2);
    return d1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int v,w;
        cin>>v>>w;
        e[i+1].push_back({v,w});
        e[v].push_back({i+1,w});
    }
    dfs(1);
    cout<<ans;
    return 0;
}