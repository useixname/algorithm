#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int f[N][N];
int n;

void prim(){
    for(int k=1;k<=n;k++){
        f[k][k]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(f[i][k]!=N&&f[k][j]!=N){
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            f[i][j]=N;
        }
    }
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        f[u][v]=1;
    }
    prim();
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<f[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=1;j<=n;j++){
            if(f[j][i]==N){
                flag=false;
            }
        }
        if(flag){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}