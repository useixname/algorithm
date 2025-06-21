#include<bits/stdc++.h>
using namespace std;
int n,ans=5010;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<=(n/3)+1;i++){
        for(int j=0;j<=(n/5)+1;j++){
            if(i*3+j*5==n){
                ans=min(ans,i+j);
            }
        }
    }
    if(ans==5010) cout<<-1;
    else cout<<ans;
    return 0;
}