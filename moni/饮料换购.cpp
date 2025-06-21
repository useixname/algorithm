#include<bits/stdc++.h>
using namespace std;
int n,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    ans=n;
    while(n>=3){
        int t=n/3;
        ans+=t;
        n%=3;
        n+=t;
    }
    cout<<ans;
    return 0;
}