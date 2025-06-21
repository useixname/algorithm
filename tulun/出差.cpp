#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
int a[N],dist[N],vis[N];
struct node{
    int v,w;
};
vector<node>e[N];
int n,m;

void dijstra(int s){
    memset(dist,0x3f3f3f3f,sizeof(dist));
    priority_queue<PII>q;
    dist[s]=0;
    q.push({0,s});
    while(q.size()){
        auto t=q.top();
        q.pop();
        int u=t.second;
        if(vis[u]) continue;
        vis[u]=1;
        for(auto et:e[u]){
            int v=et.v,w=et.w;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                q.push({-dist[v],v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w+a[v]});
        e[v].push_back({u,w+a[u]});
    }
    dijstra(1);
    cout<<dist[n]-a[n];
    return 0;
}