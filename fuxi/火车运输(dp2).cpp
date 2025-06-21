#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int f[N][N],w[N];
int n,a,b;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=a;j>=0;j--){
            for(int k=b;k>=0;k--){
                if(j>=w[i]) f[j][k]=max(f[j][k],f[j-w[i]][k]+w[i]);
                if(k>=w[i]) f[j][k]=max(f[j][k],f[j][k-w[i]]+w[i]);
            }
        }
    }
    cout<<f[a][b];
    return 0;
}