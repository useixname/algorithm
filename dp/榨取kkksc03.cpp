#include<bits/stdc++.h>
using namespace std;
const int N=250;
int n,m,t;
int a[N],b[N],f[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int k=1;k<=n;k++){
        for(int i=m;i>=a[k];i--){
            for(int j=t;j>=b[k];j--){
                f[i][j]=max(f[i][j],f[i-a[k]][j-b[k]]+1);
            }
        }
    }
    cout<<f[m][t];
    return 0;
}