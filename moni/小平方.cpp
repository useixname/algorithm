#include<bits/stdc++.h>
using namespace std;
int n,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int x=(i*i)%n;
        if(n%2==0){
            if(x<n/2){
                ans++;
            }
        }
        else{
            if(x<=n/2){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}