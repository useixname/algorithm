#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10;
int dp[1000000];

struct node{
    int iq,eq;
}a[N];
int n,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].iq>>a[i].eq;
    }
    memset(dp, -0x3f, sizeof dp);
	dp[400000] = 0;
	for(int i = 1; i <= n; i ++)
	{
		if(a[i].iq >= 0)
			for(int j = 800000; j >= a[i].iq; j --)
				dp[j] = max(dp[j], dp[j-a[i].iq] + a[i].eq);
		else
			for(int j = 0; j <= 800000 + a[i].iq; j ++)
				dp[j] = max(dp[j], dp[j-a[i].iq] + a[i].eq);
	}
	for(int i = 400000; i <= 800000; i ++)
		if(dp[i] > 0)
			ans = max(ans, i + dp[i] - 400000);
    cout<<ans;
    return 0;
}