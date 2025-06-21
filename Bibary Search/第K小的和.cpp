#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],b[N];
int n,m,k,ans;

bool chk(int mid){
    int cnt=0;
    int j=m;
    for(int i=1;i<=n;i++){
        while(j>=1&&a[i]+b[j]>mid){
            j--;
        }
        cnt+=j;
    }
    return cnt>=k;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int l=a[1]+b[1],r=a[n]+b[m];
    while(l<=r){
        int mid=l+r>>1;
        if(chk(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}