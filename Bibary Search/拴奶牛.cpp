#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int a[N],p[N];
int n,k,p1;

bool chk(int mid){
    int cnt=1,t=1;
    for(int i=1;i<=k;i++){
        if(p[i]-p[t]>=mid){
            t=i;
            cnt++;
        }
    }
    return cnt>=n;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k>>p[1];
    for(int i=2;i<=k;i++){
        p[i]=p[i-1]+((p[i-1]*2357+137)%10)+1;
    }
    int l=1,r=N;
    while(l+1<r){
        int mid=l+r>>1;
        if(chk(mid)) l=mid;
        else r=mid;
    }
    cout<<l;
    return 0;
}