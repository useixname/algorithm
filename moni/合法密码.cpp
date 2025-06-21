#include<bits/stdc++.h>
using namespace std;
string s="kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
int ans;

bool chk(string s){
    if(s.find("#")==string::npos) return false;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9') return true;
    }
    return false;
}

int main(){
    int n=s.size();
    for(int i=0;i<n;i++){
        for(int j=8;j<=16&&i+j<=n;j++){
            string t=s.substr(i,j);
            if(chk(t)){
                cout<<t<<'\n';
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}