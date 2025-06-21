#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10;
int l[N],r[N],q[N],a[N];
int n,top,ans;

//关注最小值而不是关注区间
/*
对于位置i，它所对应的最大值一定是a[i]*[r-l+1];
对于每一个位置i,如果它是某一段区间的最小值，
我们都可以向左找到第一个小于它的位置l,
向右找到第一个小于它的位置r,
那么区间[l+1,r-1]的最小值就为a[i];
所以答案对应所有a[i]的值乘以它的区间长度的最大值。
*/

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        while(top&&a[i]<a[q[top]]){
            r[q[top]]=i;
            top--;
        }
        q[++top]=i;
    }
    top=0;
    memset(q,0,sizeof(q));
    for(int i=n;i>=1;i--){
        while(top&&a[i]<a[q[top]]){
            l[q[top]]=i;
            top--;
        }
        q[++top]=i;
    }
    for(int i=1;i<=n;i++){
        // cout<<l[i]<<" "<<r[i]<<'\n';
        ans=max(ans,(r[i]-l[i]-1)*a[i]);
    }
    cout<<ans;
    return 0;
}