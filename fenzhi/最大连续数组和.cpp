#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int N=2e5+10;
int a[N],s[N];
int n;

int soved(int l,int r){
    if(l==r) return a[l];
    int mid=l+r>>1;
    int ret=max(soved(l,mid),soved(mid+1,r));

    int left=-inf,right=-inf;
    for(int i=mid-1;i>=l;i--){
        left=max(left,s[mid]-s[i-1]);
    }
    for(int i=mid+1;i<=r;i++){
        right=max(right,s[i]-s[mid]);
    }
    return max(ret,left+right);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    cout<<soved(1,n);
    return 0;
}