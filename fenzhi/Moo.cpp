#include <bits/stdc++.h>
using namespace std;
#define reg register
static int n,len[100001];
inline int pre(){
	int ans;
	for(reg int i=1;len[i-1]<n||(ans=i,0);++i)len[i]=(len[i-1]<<1)+i+2;
	return ans;
}
void dg(int m,int N){
	while(len[m-1]>N)--m;
	if(N==len[m-1]+1){putchar('m');return;}
	else if(N<=len[m-1]+m+2){putchar('o');return;}
	dg(m-1,N-len[m-1]-m-2);
}
int main(){
	scanf("%d",&n),dg(pre(),n);
	return 0;
}