#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,k,ans;
int a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    sort(a+1,a+k+1);
    int t=n-1;
    for(int i=k;i>=1;i--){
        ans+=a[i]*t;
        t-=2;
        if(t<=0) break;
    }
    cout<<ans;
    return 0;
}