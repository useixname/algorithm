#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
int f[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    f[1]=0;
    for(int i=2;i<=n;i++){
        if(i%2==0) f[i]=min(f[i-1],f[i/2])+1;
        else f[i]=f[i-1]+1;
    }
    cout<<f[n];
    return 0;
}