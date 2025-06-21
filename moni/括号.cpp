#include<bits/stdc++.h> 

using namespace std;

int main( )
{
    string s;
    cin>>s;
    int a=0,b=0;
    vector<int> stk;
    for(auto c:s){
        if(c=='(') a++;
        else b++;
    }
    if(abs(a-b)!=2){
        cout<<0;
        return 0;
    }
    stk.clear();
    int ans=0;
    if(b>a){
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push_back(1);
            }
            else{
                if(stk.size()>=0){
                    ans++;
                }
                if(stk.size()){
                    stk.pop_back();
                }
                else{
                    break;
                }
            }
        }
    }
    else{
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')'){
                stk.push_back(1);
            }
            else{
                if(stk.size()>=0){
                    ans++;
                }
                if(stk.size()){
                    stk.pop_back();
                }
                else{
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}