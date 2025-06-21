#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+10;
int n,m;
int a[10010],b[10010],f[N];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=m;j++){
           f[j]=max(f[j],f[j-a[i]]+b[i]);
        }
    }
    cout<<f[m];
    return 0;
}