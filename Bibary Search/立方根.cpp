#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n;

bool chk(int x){
    return x*x*x<=n;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    int l=1,r=n+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(chk(mid)) l=mid;
        else r=mid;
    }
    cout<<l;
    return 0;
}