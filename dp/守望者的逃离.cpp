#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int f[N];
int t,m,s;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>m>>s>>t;
    for(int i=1;i<=t;i++){
        if(m>=10){
            f[i]=f[i-1]+60;
            m-=10;
        }
        else{
            f[i]=f[i-1];
            m+=4;
        }
    }
    for(int i=1;i<=t;i++){
        f[i]=max(f[i-1]+17,f[i]);
        if(f[i]>=s){
            cout<<"Yes"<<'\n'<<i;
            return 0;
        }
    }
    cout<<"No"<<'\n'<<f[t];
    return 0;
}