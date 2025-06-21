#include<bits/stdc++.h>
using namespace std;
#define int long long
int dfs()
{
	int ans=0,k=0;
	char ch,t;
	string s;
	while(cin>>ch)
	{	
		if(ch==']')
		{
			break;
		}
		cin>>s>>k;
		if(ch=='F')
		{
			t=getchar();
			ans+=k;
		}
		else if(ch=='B')
		{
			t=getchar();
			ans-=k;
		}
		else if(ch='R')
		{
			t=getchar();
			ans+=k*dfs();
			t=getchar();
		}
		if(t==']')
		{
			break;
		}
	}
	return ans;
}
signed main()
{
	cout<<abs(dfs());
    return 0;
}