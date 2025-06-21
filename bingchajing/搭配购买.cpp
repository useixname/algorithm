#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10;
int n,m,w;
int pre[N],f[N];

struct node{
    int c,d;
}a[N];

int find(int x){
    return x==pre[x]?x:pre[x]=find(pre[x]);
}

void init(){
    for(int i=1;i<=n;i++){
        pre[i]=i;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>w;
    init();
    for(int i=1;i<=n;i++){
        cin>>a[i].c>>a[i].d;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        int pu=find(u),pv=find(v);
        if(pu!=pv){
            pre[pu]=pv;
            a[pv].c+=a[pu].c;
            a[pv].d+=a[pu].d;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<pre[i]<<" ";
    }
    for(int i=1;i<=n;i++){
        if(pre[i]==i){
            for(int j=w;j>=a[i].c;j--){
                f[j]=max(f[j-a[i].c]+a[i].d,f[j]);
            }
        }
    }
    cout<<f[w];
    return 0;
}