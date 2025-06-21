#include<bits/stdc++.h>
using namespace std;
int ret[12];
int n,k;

void dfs(int step){
    if(step==n){
        for(int i=0;i<n;i++){
            cout<<ret[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=k;i++){
        ret[step]=i;
        dfs(step+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    dfs(0);
    return 0;
}