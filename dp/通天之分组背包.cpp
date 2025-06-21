#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int f[N];
int a[N],b[N],d[N],g[N][N];
int n,m,k;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x;
        cin>>a[i]>>b[i]>>x;
        k=max(k,x);
        d[x]++;
        g[x][d[x]]=i;
    }
    for(int i=1;i<=k;i++){
        for(int j=n;j>=0;j--){
            for(int t=1;t<=d[i];t++){
                if(j>=a[g[i][t]]) f[j]=max(f[j],f[j-a[g[i][t]]]+b[g[i][t]]);
            }
        }
    }
    cout<<f[n];
    return 0;
}