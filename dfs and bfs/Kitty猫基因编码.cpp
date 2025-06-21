#include<bits/stdc++.h>
using namespace std;
string s;

int chk(string s){
    int a=0,b=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='0') a++;
        else b++;
    }
    if(a==n) return 1;
    if(b==n) return 2;
    return 3;
}

string dfs(string s){
    if(chk(s)==1) return "A";
    else if(chk(s)==2) return "B";
    else{
        int k=s.size()/2;
        return "C"+dfs(s.substr(0,k))+dfs(s.substr(k));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    cout<<dfs(s);
    return 0;
}