#include<bits/stdc++.h>
using namespace std;
int n;
int vis[10],ret[10];

void dfs(int step){
    if(step==n){
        for(int i=0;i<n;i++){
            printf("%5d",ret[i]);
        }
        printf("\n");
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
    cin>>n;
    dfs(0);
    return 0;
}