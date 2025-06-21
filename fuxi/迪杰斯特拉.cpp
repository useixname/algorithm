#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e5+10;
int d[N],vis[N],path[N];
struct node{
    int v,w;
};
vector<node>e[N];
int n,ans;

void dijstla(int s){
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
                path[u]=v;
                q.push({-d[v],v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int v,w;
        cin>>v>>w;
        e[i+1].push_back({v,w});
        e[v].push_back({i+1,w});
    }
    for(int i=1;i<=n;i++){
        dijstla(i);
        ans=min(ans,d[i]);
    }
    int st=1;
    cout<<st<<" ";
    while(path[st]){
        cout<<path[st]<<" ";
        st=path[st];
    }
    return 0;
}