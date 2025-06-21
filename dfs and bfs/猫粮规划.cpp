#include<bits/stdc++.h>
using namespace std;
const int N=45;
int a[N];
int n,l,r,ans;

void dfs(int u,int sum){
    if(sum>r) return;
    if(u==n+1){
        if(sum>=l&&sum<=r){
            ans++;
        }
        return;
    }
    dfs(u+1,sum+a[u]);
    dfs(u+1,sum);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,0);
    cout<<ans;
    return 0;
}