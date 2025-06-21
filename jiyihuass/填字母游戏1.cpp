#include<bits/stdc++.h>
using namespace std;
int n;
string s;
map<string,int>mp;

int dfs(){
    if(mp.count(s)) return mp[s];
    if(s.find("LOL")!=-1) return -1;
    if(s.find("*")==-1) return 0;
    bool flag=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='*'){
            s[i]='L';
            int ans=dfs();
            s[i]='*';
            if(ans==-1) return mp[s]=1;
            else if(ans==0) flag=true;
            s[i]='O';
            ans=dfs();
            s[i]='*';
            if(ans==-1) return mp[s]=1;
            else if(ans==0) flag=true;
        }
    }
    if(flag) return mp[s]=0;
    return mp[s]=-1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    while(n--){
        cin>>s;
        if(s.size()<3) cout<<0<<'\n';
        else cout<<dfs()<<'\n';
    }
    return 0;
}