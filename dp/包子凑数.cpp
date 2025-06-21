#include<iostream>
#include<algorithm> 
using namespace std;

int gcd(int a,int b){
	if(a%b==0){
		return b;
	}
	return gcd(b,a%b);
}
//如果一组数中的最大公约数为1,即gcd(a1,a2,a2,...,an)=1
// 那么它们不能凑成的数为有限个,否则为无数个
int main(){
	int n;
	cin>>n;
	int a[110];
	int g,ans=0;
	bool dp[100010]={false};
	dp[0]=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0){
			g=a[0];
		}
		else{
			g=gcd(g,a[i]);
		}
		for(int j=a[i];j<100010;j++){
			if(dp[j-a[i]]){
				dp[j]=true;
			}
		}
	}
	if(g!=1){
		cout<<"INF";
		return 0;
	}
	else{
		for(int i=0;i<100010;i++){
			if(!dp[i]){
				ans++;
			}
		}
		cout<<ans;
	    return 0;
	}
}