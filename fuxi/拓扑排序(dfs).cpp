#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>e[N],tp;
int c[N];//È¾É«Êý×é 0->-1->1;
int n,m;

bool dfs(int x){
    c[x]=-1;
    for(int y:e[x]){
        if(c[y]==-1) return 0;
        else if(c[y]==0) return dfs(y);
    }
    c[x]=1;
    tp.push_back(x);
    return 1;
}

bool tp_sort(){
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++){
        if(c[i]==0){
            if(dfs(i)==0) return 0;
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
    if(tp_sort()){
        for(int x:tp){
            cout<<x<<" ";
        }
    }
    return 0;
}