#include<bits/stdc++.h>
using namespace std;
#define N 300001
int n;
int a[N];
long long int sum;
double maxn;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		sum+=a[i];
		maxn=max(maxn,sum*1.0/(n-i+1)*sum);
	}
	printf("%lf",maxn);
}