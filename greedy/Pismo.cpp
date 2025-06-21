#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N];
int n,ans=0x3f3f3f3f;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]==a[i-1]){
            cout<<0;
            return 0;
        }
        else{
            ans=min(ans,abs(a[i]-a[i-1]));
        }
    }
    cout<<ans;
    return 0;
}