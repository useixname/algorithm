#include<bits/stdc++.h>
using namespace std;
char s[257];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s+1;
    bool flag=false;
    int ans1=0,ans2=0;
    for(int i=1;i<=strlen(s+1);i++){
        if(s[i]=='.') continue;
        else if(s[i]=='b'){
            ans1++;
        }
        else if(s[i]=='o'){
            if(s[i-1]!='b') ans1++;
        }
        else if(s[i]=='y'){
            if(s[i-1]!='o') ans1++;
        }
        else if(s[i]=='g'){
            ans2++;
        }
        else if(s[i]=='i'){
            if(s[i-1]!='g') ans2++;
        }
        else if(s[i]=='r'){
            if(s[i-1]!='i') ans2++;
        }
        else if(s[i]=='l'){
            if(s[i-1]!='r') ans2++;
        }
    }
    cout<<ans1<<'\n'<<ans2;
    return 0;
}