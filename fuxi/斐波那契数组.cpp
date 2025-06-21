#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int d[N],f[N];
int n,ans,cnt;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    f[1]=f[2]=1;
    for(int i=3;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x%f[i]==0){
            d[x/f[i]]++;
            cnt=max(cnt,d[x/f[i]]);
        }
    }
    cout<<n-cnt;
    return 0;
}