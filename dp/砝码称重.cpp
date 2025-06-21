#include<bits/stdc++.h>
using namespace std;
int dp[110][100010];
int w[110];
int main(){
	int n,ans=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		sum+=w[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=0;j--){
			dp[i][j]=dp[i-1][j]||dp[i-1][j+w[i]]||dp[i-1][abs(j-w[i])];
		}
	}
	for(int i=1;i<=sum;i++){
		if(dp[n][i]){
			ans++;
		}
	}
	cout<<ans;
    return 0;
} 