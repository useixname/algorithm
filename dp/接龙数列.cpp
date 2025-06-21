#include<bits/stdc++.h>
using namespace std;
int f[10];
int n,ans;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        int l=s.size();
        f[s[l-1]-'0']=max(f[s[0]-'0']+1,f[s[l-1]-'0']);
    }
    for(int i=0;i<10;i++){
        ans=max(ans,f[i]);
    }
    cout<<n-ans;
    return 0;
}