#include<bits/stdc++.h>
using namespace std;
int n,k,ans,minn=125,maxn=0;
int m[125];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        maxn=max(maxn,x);
        minn=min(minn,x);
        m[x]++;
    }
    for(int i=maxn;i>=minn;i--){
        ans+=m[i];
        if(ans>=k) break;
    }
    cout<<ans;
    return 0;
}