#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int diff[N],sum[N],a[N];
int n,m,ans1,ans2;

void insert(int l,int r,int c){
    diff[l]+=c;
    diff[r+1]-=c;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        ans1+=sum[r]-sum[l-1];
        insert(l,r,1);
    }
    for(int i=1;i<=n;i++){
        diff[i]+=diff[i-1];
    }
    sort(diff+1,diff+n+1);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        ans2+=diff[i]*a[i];
    }
    cout<<ans2-ans1;
    return 0;
}