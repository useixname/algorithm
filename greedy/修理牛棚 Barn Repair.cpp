#include<bits/stdc++.h>
using namespace std;
const int N=2e2+10;
int a[N],d[N];
int m,s,c,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>m>>s>>c;
    for(int i=1;i<=c;i++){
        cin>>a[i];
    }
    sort(a+1,a+c+1);
    for(int i=2;i<=c;i++){
        d[i-1]=a[i]-a[i-1]-1;
    }
    sort(d+1,d+c);
    ans=c;
    for(int i=1;i<=c-m;i++){
        ans+=d[i];
    }
    cout<<ans;
    return 0;
}