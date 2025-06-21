#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m;
int fa[N];

struct node{
    int u,v,w;
    bool operator<(const node & pa) const{
        return w<pa.w;
    }
}e[N];

void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}

int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

void kruskal(){
    sort(e+1,e+m+1);
    int cnt=0,ans=-0x3f3f3f3f;
    for(int i=1;i<=m;i++){
        int x=find(e[i].u),y=find(e[i].v);
        if(x!=y){
            fa[x]=y;
            ans=max(ans,e[i].w);
            cnt++;
        }
        if(cnt==n-1){
            cout<<ans;
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    kruskal();
    return 0;
}