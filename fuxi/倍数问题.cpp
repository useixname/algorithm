#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
unordered_map<int,int>mp,vis;
int n,k,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[a[i]%k]=1;
        mp[a[i]%k]=max(a[i],mp[a[i]%k]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int sum=a[i]+a[j];
            int last=(k-sum%k)%k;
            if(vis[last]) ans=max(ans,sum+mp[last]);
        }
    }
    //(a+b+c)%k=((a+b)%k+c%k)%k
    cout<<ans;
    return 0;
}