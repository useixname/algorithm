#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e2+10;
int a[N],upper[N],down[N];
int n,cnt;

int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]) continue;
        int d=gcd(a[i],a[i-1]);
        upper[++cnt]=a[i]/d;
        down[cnt]=a[i-1]/d;
    }
    int up=upper[1],dn=down[1];
    for(int i=2;i<=cnt;i++){
        up=gcd(up,upper[i]);
        dn=gcd(dn,down[i]);
    }
    cout<<up<<"/"<<dn;
    return 0;
}