#include<bits/stdc++.h>
using namespace std;
#define int long long
int k;

//一个数的阶乘末尾为0的个数等于1到N中5的倍数个数
bool chk(int n){
    int cnt=0;
    while(n>0){
        cnt+=(n/5);
        n/=5;
    }
    return cnt>=k;
}

signed main(){
    cin>>k;
    int l=0,r=0x7fffffffffffffffL;
    while(l+1<r){
        int mid=(l+r)>>1;
        if(chk(mid)) r=mid;
        else l=mid;
    }
    if(r==0x7fffffffffffffffL) r=-1;
    cout<<r;
    return 0;
}