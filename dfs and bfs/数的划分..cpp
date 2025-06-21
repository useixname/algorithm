#include<bits/stdc++.h>
using namespace std;
long long a[105];
<<<<<<< HEAD
long long n,m,sum;//n:拆分的数,k:拆分成几份,sum:有多少种
=======
long long n,k,sum;//n:拆分的数,k:拆分成几份,sum:有多少种
>>>>>>> 0e1218bc702cdab65f4d3ad81f62baa81bda875e
long long now;//已经拆分后的数字总和
void dfs(int x,int last,int k)//拆分到第几份,上一个拆分的内容
{
	if(x>k||now>n) return;
	if(x==k&&n==now)
	{
		sum++;
		return;
	}
	for(int i=last; i<=n; i++)//为了保证不重复,用从小到大的顺序进行拆分
	{
		if(now+i<=n);
		{
			now+=i;
			dfs(x+1,i,k);
			now-=i;
		}
	}
}
int main()
{
<<<<<<< HEAD
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		dfs(0,1,i);
	}
=======
	cin>>k>>n;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	dfs(0,1);
>>>>>>> 0e1218bc702cdab65f4d3ad81f62baa81bda875e
	cout<<sum;
    return 0;
}