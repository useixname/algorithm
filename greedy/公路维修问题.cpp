#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+10;
int n,m,ans;
int a[N],d[N];

bool cmp(int x,int y){
    return x>y;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(d[i]!=1) d[i-1]=a[i]-a[i-1];
    }
    ans=a[n]-a[1]+1;
    sort(d+1,d+n,cmp);
    for(int i=1;i<m;i++){
        ans-=(d[i]-1);
    }
    cout<<ans;
    return 0;
}