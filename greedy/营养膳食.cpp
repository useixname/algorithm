#include<bits/stdc++.h>
using namespace std;
const int N=2e2+10;
int a[N];
int n,m,k,ans;
struct node{
    int c,idx;
    bool operator<(const node & pa) const{
        return c>pa.c;
    }
}b[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i].c>>b[i].idx;
    }
    sort(b+1,b+n+1);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(cnt==m) break;
        if(a[b[i].idx]){
            ans+=b[i].c;
            a[b[i].idx]--;
            cnt++;
        }
    }
    cout<<ans;
    return 0;
}