#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char s[N];
int t,n,k;

bool chk(int x){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            i=i+x-1;
            cnt++;
        }
    }
    return cnt<=k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n>>k;
        cin>>s+1;
        int l=0,r=n+1;
        while(l+1<r){
            int mid=(l+r)>>1;
            if(chk(mid)) r=mid;
            else l=mid;
        }
        cout<<r<<'\n';
    }
    return 0;
}