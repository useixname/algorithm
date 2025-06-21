#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,ans;
int a[N],d[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n/2;i++){
        d[i]=a[n-i+1]-a[i];
    }
    for(int i=1;i<=n/2;i++){
        if(d[i]==0) continue;
        else if(d[i]>0){
            if(d[i+1]>0){
                int x=min(d[i],d[i+1]);
                ans+=x;
                d[i+1]-=x;
                d[i]-=x;
                if(d[i]!=0) ans+=d[i];
            }
            else{
                ans+=d[i];
            }
        }
        else{
            if(d[i+1]<0){
                int x=min(-d[i],-d[i+1]);
                ans+=x;
                d[i+1]+=x;
                d[i]+=x;
                if(d[i]!=0) ans-=d[i];
            }
            else{
                ans-=d[i];
            }
        }
    }
    cout<<ans;
    return 0;
}