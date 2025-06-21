#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[25];
int n;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    f[1]=0;f[2]=1;f[3]=2;
	if(n==1||n==2||n==3)
	{
		printf("%d",f[n]);
		return 0;
	}
	for(int i=4;i<=n;i++)
	{
		f[i]=(i-1)*(f[i-1]+f[i-2]);
	}
    cout<<f[n];
    return 0;
}