#include<bits/stdc++.h>
using namespace std;
#define inf 1<<31
const int N=2e5+10;
int n,l,r,ans=-inf;
int a[N],q[N],f[N];
int main(){
    ios_base::sync_with_stdio(0);
	scanf("%d%d%d",&n,&l,&r);
    memset(f,0xcf,sizeof(f));
	for(int i=0;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int h=1,t=0;
	f[0]=0;
	for(int i=l;i<=n;i++){
		while(h<=t&&f[q[t]]<=f[i-l]){
			t--;
		}
		q[++t]=i-l;
		while(q[h]+r<i){
			h++;
		}
		f[i]=f[q[h]]+a[i];
        if(i>=n-r+1) ans=max(ans,f[i]);
	}
	printf("%d",ans);
	return 0;
}