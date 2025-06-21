#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,k,ans;
int a[N],sum[N],q[N];
// 同余定理 诺a%k=b%k <=> (a-b)%k
signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    q[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        int x=sum[i]%k;
        q[x]++;
    }
    for(int i=0;i<k;i++){
        ans+=(q[i]*(q[i]-1))/2;//从q[i]个有着相同余数的数中选择两个，因为它们同余k,所以它们的差也余k
    }
    cout<<ans;
    return 0;
}