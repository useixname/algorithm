#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e15;
int k,l,r,s,flag;
int f[75];

void init(){
    f[1]=f[2]=1;
    for(k=3;;k++){
        f[k]=f[k-1]+f[k-2];
        if(f[k]>=N) break;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    init();
    int x;
    while(cin>>x){
        l=1;r=1;s=0;flag=0;
        while(l<=r&&r<=k){
            while(s<x) {s+=f[r];r++;}
            while(s>x) {s-=f[l];l++;}
            if(s==x) {cout<<"YES"<<'\n';flag=1;break;}
        }
        if(!flag) cout<<"NO"<<'\n';
    }
    return 0;
}