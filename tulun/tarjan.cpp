#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=5e5+10;
int fa[N],vis[N],ans[N];
vector<int>e[N];
vector<PII>query[N];
int n,m,s;

int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}

void tarjan(int u){
    vis[u]=1;
    for(auto v:e[u]){
        if(!vis[v]){
            tarjan(v);
            fa[v]=u;
        }
    }
    for(auto t:query[u]){
        int v=t.first,i=t.second;
        if(vis[v]) ans[i]=find(v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>s;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        query[u].push_back({v,i});
        query[v].push_back({u,i});
    }
    for(int i=1;i<=N;i++) fa[i]=i;
    tarjan(s);
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}