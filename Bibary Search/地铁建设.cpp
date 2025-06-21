#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e2+10;
int z[N],a[N],b[N];
int n,p;

bool chk(int x){
    int s=0;
    for(int i=1;i<=n;i++){
        if(x<=z[i]) s+=a[i]*x;
        else s+=a[i]*z[i]+b[i]*(x-z[i]);
    }
    return s>=p;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>z[i]>>a[i]>>b[i];
    }
    int l=1,r=p+1;
    while(l+1<r){
        int mid=(l+r)>>1;
        if(chk(mid)) r=mid;
        else l=mid;
    }
    cout<<r;
    return 0;
}