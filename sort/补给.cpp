#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
int n,m,ans;

struct node{
    int p,w;
    bool operator<(const node & pa) const{
        return p+w<pa.p+pa.w;
    }
}a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].p>>a[i].w;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(m>=a[i].p+a[i].w){
            ans++;
            m-=a[i].p+a[i].w;
        }
        else{
            if(m>=a[i].p/2+a[i].w){
                ans++;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}