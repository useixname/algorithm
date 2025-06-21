#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10;
int n,m;
int a[N],sum=0;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        sum+=a[i];
        if(sum>=m){
            cout<<n-i+1;
            return 0;
        }
    }
}