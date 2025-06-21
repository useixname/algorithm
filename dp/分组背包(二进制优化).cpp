//二进制优化
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int n,V;
int v[MAXN],w[MAXN];
int f[MAXN];
int main()
{
	cin>>n>>V;
	int cnt=0;//记录新的物体数 
	for(int i=1,a,b,s;i<=n;i++)
	{
		cin>>b>>a>>s;
		int k=1;
		while(k<=s)//实现1  2  4  8件原物品  合成为新物品 
		{
			v[++cnt]=k*a;
			w[cnt]=k*b;
			s-=k;
			k*=2;
		}
		if(s)
		{
			v[++cnt]=s*a;
			w[cnt]=s*b;
		}
	}
 
	for(int i=1;i<=cnt;i++)//01背包 
		for(int j=V;j>=v[i];j--)
			f[j]=max(f[j],f[j-v[i]]+w[i]);
	cout<<f[V];
	return 0;
}