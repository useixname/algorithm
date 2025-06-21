#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[3610],a[15],b[15];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=3600;j++){
            if(j>=a[i]){
                f[j%360]|=f[(j+a[i])%360];
                f[j%360]|=f[(j-a[i])%360];
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(f[b[i]]) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}