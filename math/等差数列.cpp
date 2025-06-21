#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,d=1,minn=0x3f3f3f3f,maxn=-1;
int a[N];

int gcd(int n,int m){
    if(n%m==0){
        return m;
    }
    return gcd(m,n%m);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[1]==a[n]){
        cout<<n;
        return 0;
    }
    d=a[2]-a[1];
    for(int i=3;i<=n;i++){
        d=gcd(d,a[i]-a[i-1]);
    }
    cout<<(a[n]-a[1])/d+1;
    return 0;
}