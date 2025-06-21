#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int a[N],b[N],c[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i]>>c[i];
    }
    sort(b+1,b+m+1);
    sort(a+b[m],a+n+1);
    // for(int i=b[m];i<=n;i++){
    //     cout<<a[i]<<" ";
    // }
    cout<<a[b[m]];
    return 0;
}