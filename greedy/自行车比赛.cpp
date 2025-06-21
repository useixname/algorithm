#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N],b[N];
int n,ans,maxn;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i]+n-i+1;
        if(b[i]>maxn) maxn=b[i];
    }
    for(int i=n;i>=1;i--){
        if(a[i]+n>=maxn) ans++;
        else{
            break;
        }
    }
    cout<<ans;
    return 0;
}