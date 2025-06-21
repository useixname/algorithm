#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=65;
int a[N],k;
string s;
int n;

void init(){
    a[1]=s.size();
    for(k=2;a[k-1]<=1e18;k++){
        a[k]=a[k-1]*2;
    }
}

void dfs(int x){
    if(x<=s.size()) {cout<<s[x-1];return;}
    int m=lower_bound(a+1,a+k,x)-a;
    m-=1;
    if(x==a[m]+1) dfs(a[m]);
    else dfs(x-a[m]-1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>s>>n;
    init();
    dfs(n);
    return 0;
}