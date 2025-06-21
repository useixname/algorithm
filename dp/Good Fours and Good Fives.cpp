#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
int f[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    f[0]=1;
    for(int i=1;i<=n;i++){
        if(i-4>=0) f[i]+=f[i-4];
    }
    // for(int i=1;i<=100;i++){
    //     if(f[i]) cout<<i<<":"<<f[i]<<'\n';
    // }
    for(int i=1;i<=n;i++){
        if(i-5>=0) f[i]+=f[i-5];
        if(f[i]) cout<<i<<":"<<f[i]<<'\n';
    }
    cout<<f[n];
    return 0;
}