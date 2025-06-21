#include<bits/stdc++.h>
using namespace std;
#define inf 0x7f7f7f7f
#define PII pair<int,int>
#define int long long
const int N=1e5+10;
int n,m,q,cnt;
struct node{
    int v,w;
};
vector<node>e[N];
int d[N],vis[N];

void dijkstra(int s){
    memset(d,inf,sizeof(d));
    memset(vis,0,sizeof(vis));
    priority_queue<PII>q;
    d[s]=0;
    q.push({0,s});
    while(q.size()){
        auto t=q.top();
        q.pop();
        int u=t.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto eu:e[u]){
            int v=eu.v,w=eu.w;
            if(d[v]>=(d[u]^w) || cnt==m){
                d[v]=d[u]^w;
                q.push({-d[v],v});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(w<=1) cnt++;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dijkstra(1);
    while(q--){
        int s,t;
        cin>>s>>t;
        cout<<(d[s]^d[t])<<'\n';
    }
    return 0;
}