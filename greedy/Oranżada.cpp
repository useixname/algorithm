#include<bits/stdc++.h>
using namespace std;
bool book[500001];
long long ans;
int a,n,k,d;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(book[a]==0)
		{
			book[a]=1;
			ans+=i-d-1;
			d++;
		}
		if(d==k)
		{
			cout<<ans;
			return 0;
		}
	}
	cout<<-1;
}