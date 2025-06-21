#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
char s[N],p[N];
int a[N],cnt=1,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s+1>>p+1;
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]!=p[i]){
            a[cnt++]=i;
        }
    }
    for(int i=2;i<cnt;i++){
        ans+=a[i]-a[i-1];
        i+=1;
    }
    cout<<ans;
    return 0;
}