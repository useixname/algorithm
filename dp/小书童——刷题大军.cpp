#include<bits/stdc++.h>
using namespace std;
int n,m,k,r,t=155;
int a[15],b[15],c[15],f1[155],f2[55];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k>>r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=50;j>=c[i];j--){
            f2[j]=155;
            f2[j]=min(f2[j],f2[j-c[i]]+b[i]);
        }
    }
    for(int i=k;i<=50;i++){
        t=min(t,f2[i]);
    }
    // cout<<t<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=r-t;j>=a[i];j--){
            f1[j]=max(f1[j],f1[j-a[i]]+1);
        }
    }
    cout<<f1[r-t];
    return 0;
}