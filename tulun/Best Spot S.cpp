#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=5e2+10;
int n,m,b,minn=0x3f3f3f3f,ans;
struct node{
    int v,w;
};
vector<node>e[N];
int d[N],vis[N],a[N];

void dijkstra(int s){
    memset(d,0x3f3f3f3f,sizeof(d));
    memset(vis,0,sizeof(vis));
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
    cin>>n>>b>>m;
    for(int i=1;i<=b;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++){
        int s=0;
        dijkstra(i);
        for(int j=1;j<=b;j++){
            s+=d[a[j]];
        }
        if(s<minn){
            minn=s;
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}