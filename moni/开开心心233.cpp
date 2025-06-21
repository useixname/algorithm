#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    int y=(-3+sqrt(9+8*(n+m)))/2;
    cout<<n-y;
    return 0;
}