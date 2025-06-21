#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N];
int n,l,r;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    //1 2 6 9 10
    if(n&1){
        for(int i=1;i<=n;i++){
            if(i<=n/2) l+=a[i];
            else if(i>n/2+1) r+=a[i];
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(i<=n/2) l+=a[i];
            else if(i>=n/2+1) r+=a[i];
        }
    }
    cout<<r-l;
    return 0;
}