#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,m,s;
int a[N];

bool chk(int mid){
    int cnt=0;
    for(int i=1;i<=m;i++){
        int x=a[i];
        while(x>=mid){
            x-=mid;
            cnt++;
        }
        if(x!=0) cnt++;
    }
    return cnt<=n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        s+=a[i];
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