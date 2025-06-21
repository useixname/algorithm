#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,k,maxn,minn;
int a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[n]<=2){
        maxn=(a[n]+2)*pow(2,k-1);
    }
    else{
        maxn=(a[n])*pow(2,k);
    }
    minn=a[1];
    printf("%lld",maxn-minn);
    return 0;
}