#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],b[2*N];
int n,m;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    for(int i=n+1;i<=m+n;i++){
        cin>>b[i];
    }
    sort(b+1,b+m+n+1);
    for(int i=1;i<=n;i++){
        int l=0,r=n+m+1;
        while(l+1<r){
            int mid=l+r>>1;
            if(b[mid]<=a[i]) l=mid;
            else r=mid;
        }
        int l1=lower_bound(b+1,b+n+m+1,a[i])-b;
        if(l-l1+1==2) cout<<a[i]<<" ";
    }
    return 0;
}