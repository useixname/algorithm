#include<bits/stdc++.h>
using namespace std;
string s;
string ans[7];
int cnt;
// 02/03/04

int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    int y=(s[0]-'0')*10+s[1]-'0';
    int m=(s[3]-'0')*10+s[4]-'0';
    int d=(s[6]-'0')*10+s[7]-'0';
    if(m>=60){
        ans[cnt++].append("19"+s.substr(0,2)+s.substr(3,2)+s.substr(6,2));
    }
    else{
        ans[cnt++].append("20"+s.substr(0,2)+s.substr(3,2)+s.substr(6,2));
    }
    if(d>=60){
        ans[cnt++].append("19"+s.substr(6,2)+s.substr(3,2)+s.substr(0,2));
        ans[cnt++].append("19"+s.substr(6,2)+s.substr(0,2)+s.substr(3,2));
    }
    else{
        ans[cnt++].append("20"+s.substr(6,2)+s.substr(3,2)+s.substr(0,2));
        ans[cnt++].append("20"+s.substr(6,2)+s.substr(0,2)+s.substr(3,2));
    }
    sort(ans,ans+cnt);
    for(int i=0;i<cnt;i++){
        for(int j=0;j<8;j++){
            cout<<ans[i][j];
            if(j==3||j==5){
                cout<<'-';
            }
        }
        cout<<'\n';
    }
    return 0;
}