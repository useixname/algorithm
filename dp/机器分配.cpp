#include<bits/stdc++.h>
using namespace std;
const int N=20;
int f[N][N],w[N][N];
int n,m,ans;



int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>w[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]=max(f[i][j],f[i][j]);
        }
    }
    return 0;
}