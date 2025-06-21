#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],s[N];
int n,ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=2;i<=n;i++){
        if(s[i]>=0){
            ans+=s[i];
        }
    }
    cout<<ans;
    return 0;
}