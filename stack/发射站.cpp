#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int ansL[N],ansR[N];
struct node{
    int h,w;
}a[N];
int n,ans;
stack<int>s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].h>>a[i].w;
    }
    for(int i=1;i<=n;i++){
        while(!s.empty()&&a[s.top()].h<a[i].h){
            ansL[i]+=a[s.top()].w;
            s.pop();
        }
        s.push(i);
    }
    while(s.size()) s.pop();
    for(int i=n;i>=1;i--){
        while(!s.empty()&&a[s.top()].h<a[i].h){
            ansR[i]+=a[s.top()].w;
            s.pop();
        }
        s.push(i);
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,ansL[i]+ansR[i]);
    }
    cout<<ans;
    return 0;
}