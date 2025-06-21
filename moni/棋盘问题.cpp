#include<bits/stdc++.h>
using namespace std;
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    if(n!=max(n,m)){
        swap(n,m);
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=m;i++){
        ans1+=(n-i+1)*(m-i+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i!=j){
                ans2+=(n-i+1)*(m-j+1);
            }
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}