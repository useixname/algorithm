#include<iostream>
#include<cstdio>
using namespace std;

int c,y;
long long ans = 0;
int main()
{
	int n,s;
	cin >> n >> s;
	int last;
	for(int i = 1;i <= n;++ i)
	{
		cin >> c >> y;
		if(i == 1)last = c;
		else	last = min(last + s,c);
		ans += last * y;
	}
	cout << ans << endl;
	return 0;
}