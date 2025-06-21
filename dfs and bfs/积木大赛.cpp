#include <bits/stdc++.h>
using namespace std;
int n,h[100050],ans;
int main(){
	std::cin>>n;
	for(int i=1; i<=n; i++) cin>>h[i];
	for(int i=1; i<=n; i++) if(h[i]>h[i-1]) ans+=h[i]-h[i-1];
	cout<<ans;
	return 0;
}