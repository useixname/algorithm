#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e2+10;
int k,e,n,ans;

struct node{
    int f,c;
    bool operator<(const node & pa) const{
        return c<pa.c;
    }
}a[N];


signed main(){
    ios_base::sync_with_stdio(0);
    cin>>k>>e>>n;
    for(int i=1;i<=n;i++){
        int x,b;
        cin>>x>>a[i].f>>b;
        a[i].c=e-x+b;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n&&k>0;i++){
        ans+=min(k,a[i].f)*a[i].c;
        k-=a[i].f;
    }
    cout<<ans;
    return 0;
}