#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,ans;
int l[N],r[N],a[27];
char s[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s+1;
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        l[i]=a[s[i]-'a'];
        a[s[i]-'a']=i;
    }
    for(int i=0;i<26;i++){
        a[i]=n+1;
    }
    for(int i=n;i>=1;i--){
        r[i]=a[s[i]-'a'];
        a[s[i]-'a']=i;
    }
    for(int i=1;i<=n;i++){
        ans+=(i-l[i])*(r[i]-i);
    }
    cout<<ans;
    return 0;
}