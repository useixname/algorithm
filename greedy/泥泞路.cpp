#include<bits/stdc++.h>
using namespace std;
struct note{
	int l,r;
}a[10005];
int n,m,ans;
bool cmp(const note&aa,const note&bb){
	return aa.l<bb.l;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+n+1,cmp);
	int x=0;
	for(int i=1;i<=n;i++){
		x=max(x,a[i].l);
		while(x<a[i].r){
			x+=m;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}