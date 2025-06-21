#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int vis[N],ret[N],times[N];
vector<int>e[N];
int n,m,a,b,ans;

void dfs(int x,int step){
    if(x==b){
        ans++;
        for(int i=0;i<step;i++){
            times[ret[i]]++;
        }
        return;
    }
    for(int i=0;i<e[x].size();i++){
        if(!vis[e[x][i]]){
            ret[step]=e[x][i];
            vis[e[x][i]]=1;
            dfs(e[x][i],step+1);
            vis[e[x][i]]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cin>>a>>b;
    vis[a]=1;
    dfs(a,0);
    int cnt=0;
    if(!ans){
        cout<<-1;
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            if(i!=a&&i!=b&&times[i]==ans){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}