#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int n,m,ans;

struct node{
    int x,cnt;
    bool operator<(const node & pa) const{
        if(x==pa.x){
            return cnt>pa.cnt;
        }
        return x<pa.x;
    }
}a[N];


signed main(){
    ios_base::sync_with_stdio(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].cnt;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(m-a[i].cnt>=0){
            m-=a[i].cnt;
            ans+=a[i].x*a[i].cnt;
        }
        else{
            ans+=m*a[i].x;
            break;
        }
    }
    cout<<ans;
    return 0;
}