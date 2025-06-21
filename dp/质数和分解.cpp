#include<bits/stdc++.h>
using namespace std;
const int N=2e2+10;
int vis[N],prim[N],f[N];
int n,cnt;

void get_prim(){
    for(int i=2;i<=N;i++){
        if(!vis[i]) prim[++cnt]=i;
        for(int j=1;i*prim[j]<=N;j++){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    get_prim();
    // for(int i=1;i<=cnt;i++){
    //     cout<<prim[i]<<" ";
    // }
    f[0]=1;
    for(int i=1;i<=cnt;i++){
        for(int j=prim[i];j<=N;j++){
            f[j]+=f[j-prim[i]];
        }
    }
    while(cin>>n){
        cout<<f[n]<<'\n';
    }
    return 0;
}