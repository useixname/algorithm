#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],sum[N];
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<'\n';
    }
    return 0;
}