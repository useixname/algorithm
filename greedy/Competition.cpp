#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,x,y,z,cnt,ans;
struct node{
	int x,y,z;
}a[N];
inline bool cmp(node x,node y){
	return x.z<y.z;
}
int main(){
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
		cin>>a[i].x;
	for(int i=1;i<=n;i++){
		cin>>a[i].y;
		a[i].z=a[i].x-a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=y;i++)
		ans+=a[i].y;
	for(int i=y+1;i<=n;i++)
		ans+=a[i].x;
	cout<<ans;
	return 0;
}