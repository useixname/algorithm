#include<bits/stdc++.h>
using namespace std;
int n;
string s;


int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    int flag;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]!='0'){
            flag=i;
            break;
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]!='0'){
            if(i!=flag){
                cout<<s[i]<<"*"<<n<<"^"<<s.size()-1-i<<"+";
            }
            else{
                cout<<s[i]<<"*"<<n<<"^"<<s.size()-1-i;
            }
        }
    }
    return 0;
}