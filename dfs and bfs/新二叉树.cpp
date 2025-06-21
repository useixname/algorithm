#include<bits/stdc++.h>
using namespace std;
char s[30][3];
string ans,ans1;
int n;

void dfs(int x,char rt){
    ans+=rt;
    for(int i=1;i<=n;i++){
        if(s[i][0]==s[x][1]){
            dfs(i,s[x][1]);
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i][0]==s[x][2]){
            dfs(i,s[x][2]);
        }
    }
}

void dfs1(char rt){
    if(rt!='*'){
        ans1+=rt;
        for(int i=1;i<=n;i++){
            if(s[i][0]==rt){
                dfs1(s[i][1]);
                dfs1(s[i][2]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    dfs(1,s[1][0]);
    dfs1(s[1][0]);
    cout<<ans<<'\n'<<ans1;
    return 0;
}