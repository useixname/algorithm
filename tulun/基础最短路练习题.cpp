#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x7f7f7f7f
#define PII pair<int,int>
const int N=1e5+10;

struct node{
    int v,w;
};
vector<node> e[N];
int vis[N],d[N];
int n,m,q,cnt=0;

void dijkstra(int s){
    memset(d,inf,sizeof(d));
    memset(vis,0,sizeof(vis));
    priority_queue<PII> q;
    d[s]=0;
    q.push({0,s});
    while(q.size()){
        auto t=q.top();
        q.pop();
        int u=t.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto et:e[u]){
            int v=et.v,w=et.w;
            if(d[v]>=d[u]^w||cnt==m){
                d[v]=d[u]^w;
                q.push({-d[v],v});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
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
        int a,b;
        cin>>a>>b;
        cout<<(d[a]^d[b])<<'\n';
    }
    return 0;
}