#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,p;

int quikly_pow(int n,int m){
    int ret=1;
    while(m){
        if(m&1) ret=(ret*n)%p;
        m>>=1;
        n=(n*n)%p;
    }
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>a>>b>>p;
    printf("%d^%d mod %d=%d",a,b,p,quikly_pow(a,b));
    return 0;
}