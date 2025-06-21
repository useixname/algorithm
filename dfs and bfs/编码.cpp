#include<bits/stdc++.h>
using namespace std;

const int N=35;
int a[N],vis[N];
unordered_map<string,int>ans;
int cnt;

void dfs(int u,int n,int m){
    if(u>=m){
        string s;
        for(int i=0;i<m;i++){
            s+=(a[i]-1)+'a';
        }
        ans[s]=++cnt;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&(!u||i>a[u-1])){
            vis[i]=1;
            a[u]=i;
            dfs(u+1,26,m);
            vis[i]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    for(int i=1;i<=6;i++){
        dfs(0,26,i);
    }
    string s;
    cin>>s;
    cout<<ans[s];
    return 0;
}