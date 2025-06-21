#include <stdio.h>
#include <iostream>
#define inf 2e9+7
using namespace std;
int dp[1501][1501][2],a[1501][1501],n,m,s;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	register int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==0)
			{
				dp[i][j][0]=min(min(dp[i-1][j][1],dp[i][j-1][1]),dp[i-1][j-1][0])+1;
				s=max(s,dp[i][j][0]);
			}
			if(a[i][j]==1)
			{
				dp[i][j][1]=min(min(dp[i-1][j][0],dp[i][j-1][0]),dp[i-1][j-1][1])+1;
				s=max(s,dp[i][j][1]);
			}
		}
	}
	cout<<s<<endl;
	return 0;
}