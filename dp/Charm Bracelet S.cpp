#include<bits/stdc++.h>
using namespace std;
const int N=15000;
int n,m;
int w[3500],v[3500],f[N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+v[i]);
        }
    }
    cout<<f[m];
    return 0;
}