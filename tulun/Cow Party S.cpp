#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int N=1e3+10;
int n,m,t,ans;
struct node{
    int v,w;
};
vector<node>e[N];
int d[N],vis[N];

void dijkstar(int s){
    memset(vis,0,sizeof(vis));
    memset(d,0x3f3f3f3f,sizeof(d));
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
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({-d[v],v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>t;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
    }
    for(int i=1;i<=n;i++){
        dijkstar(i);
        int temp=d[t];
        dijkstar(t);
        ans=max(ans,d[i]+temp);
    }
    cout<<ans;
    return 0;
}