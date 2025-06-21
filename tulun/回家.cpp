#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x7f7f7f7f
#define PII pair<int,int>
const int N=3e3+10;
int m,ans=inf;
char s;
struct node{
    int v,w;
};
vector<node>e[N];
int d[N],vis[N],flag[100][100];

void dijkstar(int s){
    memset(vis,0,sizeof(vis));
    memset(d,inf,sizeof(d));
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

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>m;
    for(int i=1;i<=m;i++){
        char u1,v1;
        int w,w1;
        cin>>u1>>v1>>w;
        int u=u1-'A'+1;
        int v=v1-'A'+1;
        flag[u][v]=w;
        if(flag[u][v]){
            w=min(w,flag[u][v]);
        }
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    for(int i=1;i<=25;i++){
        dijkstar(i);
        if(d[26]<ans){
            ans=d[26];
            s=i+'A'-1;
        }
    }
    cout<<s<<" "<<ans;
    return 0;
}