#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<string,int>a;
string s;
int n,m;
signed main(){
    cin>>n;
    while(n--){
    	cin>>s;
    	a[s]=1;
    }
    cin>>m;
    while(m--){
    	cin>>s;
    	if(a[s]==1) puts("OK"),a[s]=2;
    	else if(a[s]==2) puts("REPEAT");
    	else puts("WRONG");
    }
	return 0;
}