#include<bits/stdc++.h>
using namespace std;
const int N=35;
int f[N][N];
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int j=1;j<=m;j++){
        f[1][j]=1;
    }
    for(int i=1;i<=n;i++){
        f[i][1]=1;
    }
    f[1][1]=0;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(i&1||j&1){
                f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
    }
    cout<<f[n][m];
    return 0;
}