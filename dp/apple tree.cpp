#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e8+10;
int f[N],w[25];
int t,n,m;

int solvd(){
    for(int i=1;i<=m;i++){
        f[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+w[i]);
        }
    }
    return f[m];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>w[i];
        }
        cout<<solvd()<<'\n';
    }
    return 0;
}