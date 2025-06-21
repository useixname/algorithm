#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
char s[N],t[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s+1>>t+1;
    int n=strlen(s+1),m=strlen(t+1);
    int ans=1;
    for(int i=1;i<=n;i++){
        if(s[i]==t[ans]){
            ans++;
        }
    }
    cout<<ans-1;
    return 0;
}