#include<bits/stdc++.h>
using namespace std;
#define N 1000000005
bool vis[N];
#define ll long long
priority_queue <ll,vector<ll>,greater<ll> > pq;
int main(){
	ll cnt = 1,k;
	pq.push(1);
	while(cnt <= 1500)
	{
		k = pq.top();
		pq.pop();
		if(vis[k]) continue;
		vis[k] = 1;
		cnt ++;
		pq.push(2*k);
		pq.push(3*k);
		pq.push(5*k);
	}
	printf("%lld\n",k);
	return 0;
}