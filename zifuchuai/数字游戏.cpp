#include<bits/stdc++.h>
using namespace std;
string s;
int ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    for(int i=0;i<8;i++){
        if(s[i]=='1'){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}