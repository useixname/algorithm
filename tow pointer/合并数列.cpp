#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N];
int n,m,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    int s1=a[1],s2=b[1];
    int i=1,j=1;
    while(i<=n&&j<=m){
        if(s1==s2) s1=a[++i],s2=b[++j];
        if(s1<s2) s1+=a[++i],ans++;
        if(s1>s2) s2+=b[++j],ans++;
    }
    cout<<ans;
    return 0;
}