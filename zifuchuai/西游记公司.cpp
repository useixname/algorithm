#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long cpt,cpts=0,h1,m1,s1,h2,m2,s2;
	scanf("%lld:%lld:%lld",&h1,&m1,&s1);
	scanf("%lld:%lld:%lld",&h2,&m2,&s2);
	cin>>cpt;
	s1=s1+m1*60+h1*3600;
	s2=s2+m2*60+h2*3600;
	cpts=(s2-s1)*cpt;
	cout<<cpts<<endl;
	return 0;
}