#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,l,r;
string s;
int cnt;
int flag[N];
//aabaac
//aaaaaa
//aaaabb
//aaaaba
// 3 5

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>l>>r;
    l=n-l;
    r=n-r;
    cin>>s;
    for(int i=0;i<n;i++){
        if(cnt==l) break;
        if(s[i]!='a') {s[i]='a';cnt++;}
        else flag[i]=1;
    }
    if(cnt<r){
        for(int i=n-1;i>=0;i--){
            if(flag[i]) {s[i]='b';cnt++;}
            if(cnt==r) break;
        }
    }
    cout<<s;
    return 0;
}