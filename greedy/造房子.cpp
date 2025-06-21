#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,cnt;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>a>>b>>c;
    int t=min(a,b);
    int f=max(a,b)-t;
    if(c>=f){
        c-=f;
        cnt=max(a,b)+c/2;
    }
    else{
        cnt=min(a,b)+c;
    }
    // cout<<cnt<<'\n';
    int ans=(sqrt(8*cnt+1)-1)/2;
    cout<<ans;
    return 0;
}