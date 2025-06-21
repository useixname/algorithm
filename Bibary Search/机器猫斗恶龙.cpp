#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
int a[N];

bool chk(int m){
    for(int i=1;i<=n;i++){
        m+=a[i];
        if(m<=0) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int l=1,r=1e9+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(chk(mid)) r=mid;
        else l=mid;
    }
    cout<<r;
    return 0;
}