#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[1600];
int n;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    int m=n*(n+1)/2;
    if(m%2){
        cout<<0;
        return 0;
    }
    m/=2;
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=i;j--){
            f[j]+=f[j-i];
        }
    }
    cout<<f[m]/2;
    return 0;
}