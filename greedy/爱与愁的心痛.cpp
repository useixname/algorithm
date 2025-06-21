#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e3+10;
int a[N];


signed main(){
    ios_base::sync_with_stdio(0);
    int n,m,k=1,s=0,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(k<=m){
            s+=a[i];
            ans=s;
            k++;
        }
        else{
            s-=a[i-m];
            s+=a[i];
            ans=min(ans,s);
        }
    }
    cout<<ans;
    return 0;
}