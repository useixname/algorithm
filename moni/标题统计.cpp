#include<bits/stdc++.h>
using namespace std;
string s;
int ans;

int main(){
    ios_base::sync_with_stdio(0);
    getline(cin,s,'\n');
    for(int i=0;i<s.size();i++){
        if(s[i]!=' '&&s[i]!='\n'){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}