#include<bits/stdc++.h>
using namespace std;
int vis[11],ret[11];
int n,m;

void dfs(int step){
    if(step==m+1){
        for(int i=1;i<=m;i++){
            cout<<ret[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            ret[step]=i;
            dfs(step+1);
            vis[i]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    dfs(1);
    return 0;
}