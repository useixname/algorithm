#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10;
int n,ans;
int a[N];
signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        while(a[i]!=i){
            swap(a[i],a[a[i]]);
            ans++;
        }
    }
    cout<<ans;
    return 0;
}