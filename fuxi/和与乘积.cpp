#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
int n,ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int sum=0,mul=1;
        for(int j=i;j<=n;j++){
            sum+=a[j];
            mul*=a[j];
            if(sum==mul) ans++;
        }
    }
    cout<<ans;
    return 0;
}