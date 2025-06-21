#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
vector<int>e[N],tp;
int c[N];

bool dfs(int x){
    c[x]=-1;
    for(int y:e[x]){
        if(c[y]<0) return 0;
        else if(!c[y]){
            if(!dfs(y)) return 0;
        }
    }
    c[x]=1;
    tp.push_back(x);
    return 1;
}

bool tpsort(){
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++){
        if(!c[i]){
            if(!dfs(i)) return 0;
        }
    }
    reverse(tp.begin(),tp.end());
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
    }
    tpsort();
    return 0;
}