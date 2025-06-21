#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,w,l=0x3f3f3f3f,r,ans=-1;
int a[N],s[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>w;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        l=min(l,x);
        r=max(r,x);
        a[x]+=y;
    }
    for(int i=l;i<=r;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=l;i<=r;i++){
        ans=max(ans,s[i+w-1]-s[i-1]);
    }
    cout<<ans;
    return 0;
}