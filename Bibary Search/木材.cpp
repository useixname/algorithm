#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=2e5+10;
int a[N],b[N],c[N];
int n,s,l;

bool chk(int mid){
    memset(c,0,sizeof(c));
    int cnt=0;
    for(int i=1;i<=n;i++){
        c[i]=a[i]+mid*b[i];
        if(c[i]>=l) cnt+=c[i];
    }
    return cnt>=s;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s>>l;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int l=1,r=1e18;
    while(l+1<r){
        int mid=l+r>>1;
        if(chk(mid)) r=mid;
        else l=mid;
    }
    cout<<r;
    return 0;
}