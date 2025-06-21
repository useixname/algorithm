#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 100000007;
const int N=1e3+10;
int f[N][N];
int n,s,a,b;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s>>a>>b;
    if(n==1){
        cout<<1;
        return 0;
    }
    f[0][0]=1;
    for(int i=0;i<n-1;i++){
        for(int r=0;r<n;r++){
            if(f[i][r]==0) continue;
            int w=n-(i+1);
            int r1=((r+a*w)%n+n)%n;
            f[i+1][r1]=(f[i+1][r1]+f[i][r])%MOD;
            int r2=((r+(-b)*w)%n+n)%n;
            f[i+1][r2]=(f[i+1][r2]+f[i][r])%MOD;
        }
    }
    int r=(s%n+n)%n;
    cout<<f[n-1][r]%MOD;
    return 0;
}