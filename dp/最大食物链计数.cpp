#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,mod=80112002;
int f[N];
int n,m,ans;
vector<int>e[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++) f[i]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<e[i].size();j++){
            f[i]=max(f[i],f[e[i][j]]+1);
        }
        ans=max(ans,f[i]);
    }
    cout<<ans%mod;
    return 0;
}