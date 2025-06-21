#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,b;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>a>>b>>n;
    int x=a*5+b*2;
    int k=n/x;
    int ans=k*7;
    int t=n-k*x;
    if(t==0){
        cout<<ans;
    }
    else{
        if(t<=a) cout<<ans+1;
        else if(t<=2*a) cout<<ans+2;
        else if(t<=3*a) cout<<ans+3;
        else if(t<=4*a) cout<<ans+4;
        else if(t<=5*a) cout<<ans+5;
        else if(t<=5*a+b) cout<<ans+6;
        else cout<<ans+7;
    }
    return 0;
}