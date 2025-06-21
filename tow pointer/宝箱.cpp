#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,k,ans;
int a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int i=1,j=1,s=0;
    while(i<=n&&j<=n){
        if(a[j]-a[i]<=k){
            s+=a[j];
            ans=max(ans,s);
            j++;
        }
        else{
            s=0;
            i++;
            j=i;
        }
    }
    cout<<ans;
    return 0;
}