#include<bits/stdc++.h>
using namespace std;
int ans;

int main(){
    ios_base::sync_with_stdio(0);
    for(int i=1;i<=5;i++){
        int x;
        cin>>x;
        int a1=x%10;
        int a2=(x/10)%10;
        int a3=(x/100)%10;
        int a4=x/1000;
        if(a2==a4&&a3+1==a1){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}