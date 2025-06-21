#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,ans;
int a[N],f[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        f[i]=1;
        for(int j=1;j<i;j++){
            if(a[j]<a[i]){
                f[i]=max(f[j]+1,f[i]);
            }
        }
        ans=max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}