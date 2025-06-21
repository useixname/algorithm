#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,n;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>x>>n;
    int ans=1;
    for(int i=1;i<=n;i++){
        ans+=ans*x;
    }
    cout<<ans;
    return 0;
}