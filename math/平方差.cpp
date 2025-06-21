#include<bits/stdc++.h>
using namespace std;
int n,m,ans;

int main()
{
	cin>>n>>m;
	ans=(m+1)/2-n/2;
	ans+=m/4-(n-1)/4;
	cout<<ans;
    return 0;
}
