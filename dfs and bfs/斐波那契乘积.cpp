#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=86;
int t,ans;
int p[N];

void init(){
    p[1]=p[2]=1;
    for(int cnt=2;cnt<=N;cnt++){
        p[cnt]=p[cnt-1]+p[cnt-2];
    }
}

int dfs(int x,int k){
    if(x==1){
        return 1;
    }
    if(k<=2){
        return 0;
    }
    int ans=0;
    while(x<p[k]) k--;
    if(x%p[k]==0){
        ans+=dfs(x/p[k],k);
    }
    return ans+dfs(x,k-1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>t;
    init();
    while(t--){
        int x;
        cin>>x;
        cout<<dfs(x,N)<<'\n';
    }
    return 0;
}