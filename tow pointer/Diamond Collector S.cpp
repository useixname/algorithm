#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e4+10;
int a[N],l[N],r[N];
int n,k,ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    l[1]=r[n]=1;
    for(int i=2,now=1;i<=n;i++){
        while(a[i]-a[now]>k) now++;
        l[i]=max(l[i-1],i-now+1);
    }
    for(int i=n-1,now=n;i>=1;i--){
        while(a[now]-a[i]>k) now--;
        r[i]=max(r[i+1],now-i+1);
    }
    for(int i=1;i<n;i++){
        ans=max(ans,l[i]+r[i+1]);
    }
    cout<<ans;
    return 0;
}