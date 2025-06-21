#include<bits/stdc++.h>
using namespace std;
int n,ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    int t=1,k=1,flag=1;
    while(t<=n){
        if(t>flag){
            k++;
            flag+=k;
        }
        ans+=k;
        t++;
    }
    cout<<ans;
    return 0;
}