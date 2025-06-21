#include<bits/stdc++.h>
using namespace std;
int n,ans,ans1;
int fx[6]={-1,0,1,0};
int fy[6]={0,1,0,-1};//方向数组
char d[1010][1010],f[1010][1010]; 
void dfs(int x,int y) //求淹没后有几个大陆 
{
	d[x][y] = '.';
	for(int i = 0;i < 4;i++) 
	{
		int xt = x + fx[i],yt = y + fy[i];
		if(d[xt][yt] != '.' && xt > 0 && xt <= n && yt > 0 && yt <= n) dfs(xt,yt);
	}
	return;
}
void df(int x,int y)//求淹没前有几个大陆 
{
	f[x][y] = '.';
	for(int i = 0;i < 4;i++) 
	{
		int xt = x + fx[i],yt = y + fy[i];
		if(f[xt][yt] == '#' && xt > 0 && xt <= n && yt > 0 && yt <= n) df(xt,yt);
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			cin >> d[i][j],f[i][j] = d[i][j];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++) 
			if(d[i][j] == '#' && (d[i-1][j] == '.' || d[i+1][j] == '.' || d[i][j-1] == '.' || d[i][j+1] == '.')) 
				d[i][j] = '-'; 
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(f[i][j] == '#')
			{
				ans1++;
				df(i,j);
			}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(d[i][j] == '#')
			{
				ans++;
				dfs(i,j);
			}
	printf("%d",ans1 - ans);
	return 0;
}