#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,mod=10007;
int c[N][N];

void get_c(){
    c[1][1]=1;
    for(int i=2;i<=N;i++){
        for(int j=0;j<=i;j++){
            if(j==1) c[i][j]=i;
            else if(j==i) c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
}

int quikly_pow(int n,int m){
    int ret=1;
    while(m){
        if(m&1) ret=ret*n%mod;
        m>>1;
        n=n*n%mod;
    }
    return ret%mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    get_c();
    
    return 0;
}