#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=5e4+10;
int n,m,b;
struct node{
    int v,w;
};
vector<node>e[N];
int d[N],vis[N];

void dijkstra(int s){
    memset(d,0x3f3f3f3f,sizeof(d));
    d[s]=0;
    priority_queue<PII>q;
    q.push({0,s});
    while(q.size()){
        auto t=q.top();
        q.pop();
        int u=t.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto eu:e[u]){
            int v=eu.v,w=eu.w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({-d[v],v});
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>b;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dijkstra(1);
    for(int i=1;i<=b;i++){
        int s,t;
        cin>>s>>t;
        cout<<d[s]+d[t]<<'\n';
    }
    return 0;
}