#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int n;


bool chk(int m){
    int cnt=m;
    int x=m;
    while(x>=3){
        int t=x/3;
        cnt+=t;
        x-=t*3;
        x+=t;
    }
    return cnt>=n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    int l=1,r=N;
    while(l+1<r){
        int mid=l+r>>1;
        if(chk(mid)) r=mid;
        else l=mid;
    }
    cout<<r;
    return 0;
}