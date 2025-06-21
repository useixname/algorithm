#include<bits/stdc++.h>
using namespace std;
int n,m,ans;

bool chk(int x,int k){
    int num_a=0,num_b=0;
    for(int i=k;i>=1;i--){
        bitset<32> bs=x;
        num_b+=bs.count(); 
        num_a+=i-bs.count();
        x^=(x>>1);
        x&=(1<<(i-1))-1;
        if(num_a>n||num_b>m) return false;
    }
    return num_a==n&&num_b==m;
}

int main(){
    cin>>n>>m;
    //k*(k+1)/2=n+m
    int k=sqrt(2*(n+m));
    for(int i=0;i<(1<<k);i++){
        if(chk(i,k)) ans++;
    }
    cout<<ans;
    return 0;
}