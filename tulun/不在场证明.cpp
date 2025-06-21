#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=5e2+10;
int d[N],vis[N],ans[N];
int f,p,c,m,cnt;
struct node{
    int v,w;
};
vector<node>e[N];

void dijkstra(int s){
    memset(d,0x3f3f3f3f,sizeof(d));
    memset(vis,0,sizeof(vis));
    priority_queue<PII, vector<PII>, greater<>> q;
    d[s]=0;
    q.push({0,s});
    while(q.size()){
        auto t=q.top();
        q.pop();
        int u=t.second;
        if(vis[u]) continue;
        for(auto eu:e[u]){
            int v=eu.v,w=eu.w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>f>>p>>c>>m;
    for(int i=1;i<=p;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dijkstra(1);
    for(int i=1;i<=c;i++){
        int x;
        cin>>x;
        if(d[x]<=m) ans[++cnt]=i;
    }
    cout<<cnt<<'\n';
    sort(ans+1,ans+cnt+1);
    for(int i=1;i<=cnt;i++) cout<<ans[i]<<'\n';
    return 0;
}