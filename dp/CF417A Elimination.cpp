#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int f[N];
int c,d,n,m,k;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>c>>d>>n>>m>>k;
    for(int i=0;i<=n*m;i++){
        if(i>=c) f[i]=max(f[i],f[i-c]+n);
        if(i>=d) f[i]=max(f[i],f[i-d]+1);
    }
    for(int i=0;i<=n*m;i++){
        if(f[i]+k>=n*m){
            cout<<i;
            break;
        }
    }
    return 0;
}