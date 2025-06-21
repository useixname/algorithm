#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int a[101],b[20001];
int f[20001];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n+n;i++){
        f[i]=-inf;
    }
    f[1]=0;
    for(int j=1;j<=n+n;j++){
        for(int i=1;i<=m;i++){
            if(j-1>=a[i]){
                f[j]=max(f[j],f[j-a[i]]+b[j-a[i]]);
            }
        }
    }
    int ans=-inf;
    for(int i=n+1;i<=n+n;i++){
        ans=max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}