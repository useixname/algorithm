#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+10;
int n,ans;

struct node{
    int l,r;
    bool operator<(const node & pa) const{
        return l<pa.l;
    }
}a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
    }
    sort(a+1,a+n+1);
    int start=a[1].l,end=a[1].r;
    ans+=end-start;
    for(int i=2;i<=n;i++){
        if(a[i].l<end){
            if(a[i].r<end) continue;
            else{
                start=end;
                end=a[i].r;
            }
        }
        else{
            start=a[i].l;
            end=a[i].r;
        }
        ans+=end-start;
    }
    cout<<ans;
    return 0;
}