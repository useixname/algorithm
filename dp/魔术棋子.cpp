#include<bits/stdc++.h>
using namespace std;
const int N=110;
int f[N][N][N],a[N][N];
int n,m,k,cnt;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    f[1][0][1]=f[0][1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int t=0;t<k;t++){
                if(f[i-1][j][t]==1||f[i][j-1][t]==1){
                    f[i][j][(t*a[i][j])%k]=1;
                }
            }
        }
    }
    for(int i=0;i<k;i++){
        if(f[n][m][i]==1){
            cnt++;
        }
    }
    cout<<cnt<<'\n';
    for(int i=0;i<k;i++){
        if(f[n][m][i]==1){
            cout<<i<<" ";
        }
    }
    return 0;
}