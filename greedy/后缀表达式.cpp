#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N];
int n,m,ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n+m+1;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+m+2);
    if(!m){
        for(int i=1;i<=n+m+1;i++){
            ans+=a[i];
        }
    }
    else{
        ans=a[n+m+1]-a[1];
        for(int i=2;i<=n+m;i++){
            ans+=abs(a[i]);
        }
    }
    cout<<ans;
    return 0;
}