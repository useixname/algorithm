#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        ans2+=x;
    }
    for(int i=1;i<=n-1;i++){
        int a,b;
        cin>>a>>b;
        ans1+=b;
    }
    ans1*=2;
    cout<<ans1<<" "<<ans2;
    return 0;
}