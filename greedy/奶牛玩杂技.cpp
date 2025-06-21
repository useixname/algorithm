#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e4+10;
struct node{
    int w,c;
    bool operator<(const node & pa) const{
        return w+c<pa.w+pa.c;
    }
}a[N];
int n,ans=-0x3f3f3f3f;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].w>>a[i].c;
    }
    sort(a+1,a+n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i-1].w;
        ans=max(ans,sum-a[i].c);
    }
    cout<<ans;
    return 0;
}