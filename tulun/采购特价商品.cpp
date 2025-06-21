#include<bits/stdc++.h>
using namespace std;
#define PII pair<double,int>
const int N=1e2+10;
int n,m;
struct point{
    int x,y;
}a[N];
struct node{
    int v;
    double w;
};
vector<node>e[N];
double d[N];
int vis[N];

void dijkstra(int s){
    memset(vis,0,sizeof(vis));
    priority_queue<PII>q;
    d[s]=0;
    q.push({0,s});
    while(q.size()){
        auto t=q.top();
        int u=t.second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto eu:e[u]){
            int v=eu.v;
            double w=eu.w;
            double o=d[v];
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({-d[v],v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        d[i]=0x3f3f3f3f;
        cin>>a[i].x>>a[i].y;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        double w=sqrt(pow((a[u].x-a[v].x),2)+pow((a[u].y-a[v].y),2));
        // cout<<w<<'\n';
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    int s,t;
    cin>>s>>t;
    dijkstra(s);
    // for(int i=1;i<=n;i++){
    //     printf("%.2lf ",d[i]);
    // }
    printf("%.2lf",d[t]);
    return 0;
}