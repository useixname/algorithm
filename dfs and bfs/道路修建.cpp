#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=10000010;
ll n,cnt=1,ans;
ll sized[maxn],head[maxn];
struct node
{
	int w,to,nt;
}e[maxn*2];

void add(int x,int y,int z)
{
	e[cnt].to=y;
	e[cnt].nt=head[x];
	e[cnt].w=z;
	head[x]=cnt++;
}

void dfs(int x,int fa)
{
	sized[x]=1;
	for(int i=head[x];i;i=e[i].nt)
	{
		int to=e[i].to;
		if(fa==to) continue;
		dfs(to,x);
		sized[x]+=sized[to];
		ans+=e[i].w*abs(2*sized[to]-n);
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}