#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m;
int a[N],f[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m+=a[i];
    }
    m/=2;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i];j--){
            f[j]=max(f[j-a[i]]+a[i],f[j]);
        }
    }
    cout<<f[m];
    return 0;
}