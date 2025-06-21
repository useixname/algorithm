#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e4+10;
int a[N],b[N];
int n,x,y,ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        int t=a[i]-b[i];
        if(t>0) ans+=t*y;
        if(t<0) ans-=t*x;
    }
    cout<<ans;
    return 0;
}