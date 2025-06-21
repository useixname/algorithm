#include <iostream>
#include <set>
#include <cstring>
using namespace std;
int dp[200005],m;
set<string> s[20];
int main(){
	string tp;
	while (cin>>tp){
		if (tp==".") break;
		s[tp.size()].insert(tp);
		m=max(m,int(tp.size()));
	}
	int i,ans=0;
	dp[0]=1;
	string n;
	n=" ";
	while (cin>>tp){
		n=n+tp;
	}
	for (i=1;i<n.size();i++){
		for (int j=min(i,m);j>=1;j--){
			string tt=n.substr(i-j+1,j);
			if (s[tt.size()].count(tt)==1&&dp[i-j]==1){
				ans=i;
				dp[i]=1;
				break;
			}
		}
	}
	cout<<ans;
}
