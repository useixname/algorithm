#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
int a[N],f[N][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[1][1]=f[2][1]=0;
    f[1][0]=a[1],f[2][0]=a[2];
    for(int i=3;i<=n;i++){
        f[i][0]=min(f[i-1][0]+a[i],f[i-1][1]+a[i]);
        f[i][1]=min(f[i-1][0],f[i-2][0]);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<f[i][0]<<" "<<f[i][1]<<'\n';
    // }
    cout<<min(f[n][0],f[n][1]);
    return 0;
}