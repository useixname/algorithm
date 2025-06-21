#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],b[N],c[N],l[N],r[N];
int n,ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
//     3
// 1 1 1
// 2 2 2
// 3 3 3
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(a+1,a+n+1);sort(b+1,b+n+1);sort(c+1,c+n+1);
    for(int i=1;i<=n;i++){
        l[i]=(lower_bound(a+1,a+n+1,b[i])-a-1);
        int pos=upper_bound(c+1,c+n+1,b[i])-c;
        if(pos<=n) r[i]=n-pos+1;
        ans+=l[i]*r[i];
    }
    cout<<ans;
    return 0;
}