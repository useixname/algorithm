#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int n,m;

bool chk(int mid){
    int ret=0;
    for(int i=1;i<=n;i++){
        ret+=a[i]/mid;
    }
    return ret>=m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=0,r=1e8+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(chk(mid)) l=mid;
        else r=mid;
    }
    cout<<l;
    return 0;
}