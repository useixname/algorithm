#include<bits/stdc++.h>
using namespace std;
int ans;
string s;

void dfs(string s){
    int mid=s.size()/2;
    string s1=s.substr(0,mid),s2=s.substr(mid);
    reverse(s2.begin(),s2.end());
    // cout<<s1<<" "<<s2<<'\n';
    if(!s1.compare(s2)) dfs(s1);
    else ans=s.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    dfs(s);
    cout<<ans;
    return 0;
}