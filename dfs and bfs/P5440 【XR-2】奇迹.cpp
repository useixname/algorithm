#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
unordered_map<int,int>prim,vis;
int n,cnt,m;

void get_prim(){
    for(int i=2;i<=N;i++){
        if(!vis[i]){
            prim[++cnt]=i;
        }
        for(int j=1;i*prim[j]<=N;j++){
            vis[i*prim[j]]=true;
            if(i%prim[j]==0) break;
        }
    }
}

bool chk(string s){
    int d=stoi(s.substr(6));
    if(vis[d]) return false;
    int m=stoi(s.substr(4));
    if(vis[m]) return false;
    int y=stol(s.substr(0));
    if(vis[y]) return false;
    return false;
}

int dfs(string s,int u){
    if(s[u]=='-'){
        
    }
    int ret=0;
    for(int i=7;i>=0;i++){
        if(s[i]=='-'){
            if(i=4){
                for(int j=0;j<=1;j++){
                    s[i]=j+'0';
                }
            }
            else if(i==5){
                if(s[i-1]=='0'){
                    for(int j=1;j<=9;j++){
                        s[i]=j+'0';
                    }
                }
                else if(s[i-1]=='1'){
                    for(int j=0;j<=2;j++){
                        s[i]=j+'0';
                    }
                }
            }
            else if(i==6){
                for(int j=0;j<=3;j++){
                    s[i]=j+'0';
                }
            }
            else if(i==7){
                if(s[i-1]=='0'){
                    for(int j=1;j<=9;j++){
                        s[i]=j+'0';
                    }
                }
                else if(s[i-1]=='3'){
                    for(int j=0;j<=1;j++){
                        s[i]=j+'0';
                    }
                }
                else{
                    for(int j=0;j<=9;j++){
                        s[i]=j+'0';
                    }
                }
            }
            else{
                for(int j=0;j<=9;j++){
                    s[i]=j+'0';
                }
            }
        }
    }
    if(chk(s)) ret++;
}

int main(){
    ios_base::sync_with_stdio(0);
    get_prim();
    cin>>n;
    while(n--){
        m=0;
        string s;
        cin>>s;
        for(int i=0;i<8;i++){
            if(s[i]=='-'){
                m++;
            }
        }
        cout<<dfs(s,0)<<'\n';
    }
    return 0;
}