#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,ans=-1010;
int dp[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    cin>>dp[1];
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        if(dp[i-1]>=0) dp[i]=dp[i-1]+x;
        else dp[i]=x;
        ans=max(dp[i],ans);
    }
    cout<<ans;
    return 0;
}