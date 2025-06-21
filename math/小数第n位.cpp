#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,n;

int q_pow(int a,int b,int p){
    int ret=1;
    while(b){
        if(b&1) ret=ret*a%p;
        b=b>>1;
        a=a*a%p;
    }
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>a>>b>>n;
    a%=b;
    a*=q_pow(10,n-1,b);
    a%=b;
    for(int i=1;i<=3;i++){
        a*=10;
        cout<<a/b;
        a%=b;
    }
    return 0;
}