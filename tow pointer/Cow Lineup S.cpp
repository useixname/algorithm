#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
set<int>s,s1;
unordered_map<int,int>m;
struct node{
    int x,id;
    bool operator<(const node & pa) const{
        if(x==pa.x) return id<pa.id;
        return x<pa.x;
    }
}a[N];
int n,ans=0x3f3f3f3f;

signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].id;
        s.insert(a[i].id);
    }
    int k=s.size();
    sort(a+1,a+n+1);
    int s=1,t=1;
    while(t<=n){
        if(s<t&&a[s].id==a[t].id) s++;
        if(s1.size()<k) t++;
        else{
            s++;
            ans=min(ans,a[t].x-a[s].x);
            
        }
    }
    cout<<ans;
    return 0;
}