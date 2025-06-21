#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],b[N];
int n,m,ans,x;

bool chk(int x){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]<x) continue;
        int k=(a[i]-x)/b[i];
        // 10 5  (10-5)/5=1 1+1=2;
        cnt+=(k+1);
    }
    return cnt>=m;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int l=1,r=1e6;
    while(l<=r){
        int mid=(l+r)>>1;
        if(chk(mid)){
            x=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    //第m大的数为x
    //数列单调递减
    //如果存在一个数列中没有大于x的数，它就不会被统计
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]<x) continue;
        int k=(a[i]-x)/b[i];
        if(a[i]-x!=k*b[i]) k++;
        // 19 14 9 4         (19-5)/5=2 2+1=3
        cnt+=k;
        ans+=(a[i]+(a[i]-(k-1)*b[i]))*k/2;
    }
    if(cnt<m){
        ans+=(m-cnt)*x;
    }
    cout<<ans;
    return 0;
}