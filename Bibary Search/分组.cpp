#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int n,k;

bool chk(int mid){
    int cnt=1,st=a[1];
    for(int i=1;i<=n;i++){
        if(a[i]-st>mid){
            cnt++;
            st=a[i];
        }
    }
    return cnt<=k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=0,r=1e9;
    while(l<r){
        int mid=l+r>>1;
        if(chk(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}