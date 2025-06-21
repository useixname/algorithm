#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int a[N],b[N];
int n,m;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int s=1,ans=0;
    for(int i=1;i<=m;i++){
        if(b[i]>=a[s]){
            ans+=b[i];
            s++;
        }
        if(s>n) break;
    }
    s--;
    if(s<n){
        cout<<"you died!";
    }
    else{
        cout<<ans;
    }
    return 0;
}