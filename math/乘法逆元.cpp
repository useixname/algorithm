#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+10;
int inv[N];
int mod,n;
//inv[1]=1;inv[i]=-(mod/i)*inv[mod%i]
void get_inv(){
    inv[1]=1;
    cout<<inv[1]<<'\n';
    for(int i=2;i<=n;i++){
        inv[i]=-(mod/i)*inv[mod%i];
        inv[i]=(inv[i]%mod+mod)%mod;
        cout<<inv[i]<<'\n';
    }
}


signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>mod;
    get_inv();
    return 0;
}