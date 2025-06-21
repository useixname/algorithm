#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int d[N];
int n,m;

bool chk(int l){
    int cnt=0;
    for(int i=1;i<n;i++){
        if(d[i]>l){
            cnt+=(d[i]-1)/l;
        }
    }
    return cnt-1<=m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    int pre;
    cin>>pre;
    int l=0,r=0;
    for(int i=1;i<n;i++){
        int cur;
        cin>>cur;
        d[i]=cur-pre;
        r=max(r,d[i]);
        pre=cur;
    }
    while(l+1<r){
        int mid=(l+r)>>1;
        if(chk(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<r;
    return 0;
}