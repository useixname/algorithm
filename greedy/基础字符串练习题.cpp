#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int ans,maxn,cnt1;
char a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>a+1;
    int n=strlen(a+1);
    for(int i=1;i<=n;i++){
        if(a[i]=='1') cnt1++;
    }
    if(cnt1==n){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]=='0') ans++;
        else ans--;
        if(ans<0) ans=0;
        maxn=max(maxn,ans);
    }
    cout<<maxn;
    return 0;
}