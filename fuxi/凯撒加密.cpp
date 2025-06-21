#include<bits/stdc++.h>
using namespace std;
string s;

int main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        s[i]='a'+((s[i]-'a')+3)%26;
    }
    cout<<s;
    return 0;
}