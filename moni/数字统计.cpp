#include<bits/stdc++.h>
using namespace std;
int l,r,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        int x=i;
        while(x){
            int t=x%10;
            x/=10;
            if(t==2) ans++;
        }
    }
    cout<<ans;
    return 0;
}