#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],f[N],idx[N],pre[N];
int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int len=0;
    for(int i=1;i<=n;i++){
        int pos=lower_bound(f+1,f+len+1,a[i])-f;
        if(pos>len){
            f[++len]=a[i];
            idx[len]=i;
        }
        else{
            f[pos]=a[i];
            idx[pos]=i;
        }
        if(pos>1){
            pre[i]=idx[pos-1];
        }
    }
    int cur=idx[len];
    vector<int>ans;
    while(cur){
        ans.push_back(a[cur]);
        cur=pre[cur];
    }
    reverse(ans.begin(),ans.end());
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}