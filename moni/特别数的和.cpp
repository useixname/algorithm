#include<bits/stdc++.h>
using namespace std;
int n,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x=i;
        while(x){
            int t=x%10;
            if(t==2||t==0||t==1||t==9){
                ans+=i;
                break;
            }
            x/=10;
        }
    }
    cout<<ans;
    return 0;
}