#include<bits/stdc++.h>
using namespace std;
int n,ans;
int vis[25];
struct node{
    int x,y;
}a[25];

void dfs(int step){
    if(step==n+1){
        ans++;
        return;
    }
    if(!vis[a[step].x]) vis[a[step].x]=1,dfs(step+1),vis[a[step].x]=0;
    if(!vis[a[step].y]) vis[a[step].y]=1,dfs(step+1),vis[a[step].y]=0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    dfs(1);
    cout<<ans;
    return 0;
}