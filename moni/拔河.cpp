#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N],b[N];
int n,ans=0x7f7f7f7f;
vector<int>q;


signed main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int s=0;
        for(int j=i;j<=n;j++){
            s+=a[j];
            q.push_back(s);
        }
    }
    int l=q.size();
    sort(q.begin(),q.end());
    for(int i=1;i<n;i++){
        ans=min(ans,q[i]-q[i-1]);
    }
    cout<<ans;
    return 0;
}