#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,d,k,q[N];
bool vis[N];

struct node{
    int ts,id;
    bool operator<(const node & pa) const{
        if(id==pa.id) return ts<pa.ts;
        return id<pa.id;
    }
}a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>d>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i].ts>>a[i].id;
    }
    sort(a+1,a+n+1);
    int h=1,t=0;
    for(int i=1;i<=n;i++){
        if(a[i].id!=a[i-1].id) h=1,t=0;
        while(h<=t&&a[i].ts-a[q[t]].ts>=d) t--;
        q[++t]=i;
        if(q[h]<i-k+1) h++;
        if(t-h+1>=k&&!vis[a[i].id]) vis[a[i].id]=true,cout<<a[i].id<<'\n';
    }
    return 0;
}

// 0 1
// 9 1
// 10 1
// 100 3
// 100 3
// 0 10
// 10 10